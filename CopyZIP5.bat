@echo on
setlocal enabledelayedexpansion enableextensions

:: --- Demande du dossier contenant les ZIP ---
:ask_path
echo Entrez le chemin du dossier contenant les fichiers ZIP:
set /p "zip_folder="
set "zip_path=%cd%\%zip_folder%"
if not exist "%zip_path%" (
    cls
    echo [ERREUR] Le dossier "%zip_path%" n'existe pas.
    goto ask_path
)

:: --- Demande du dossier de destination ---
:ask_destination
echo Entrez le chemin du dossier de destination pour les fichiers extraits:
set /p "dest_folder="
set "dest_path=%cd%\%dest_folder%"
if not exist "%dest_path%" (
    cls
    echo [ERREUR] Le dossier "%dest_path%" n'existe pas.
    goto ask_destination
)

echo.
echo ---------- Traitement automatique de tous les fichiers ZIP ----------
echo Dossier source: %zip_path%
echo Dossier de destination: %dest_path%
echo.

:: --- Boucle sur tous les ZIP ---
for %%z in ("%zip_path%\*.zip") do (
    echo.
    echo === Traitement de %%~nxz ===

    :: Crée un dossier temporaire unique et aléatoire pour ce ZIP
    set "tmp_extract=%temp%\zip_extract_%%RANDOM%%RANDOM%%RANDOM%%RANDOM%"
    md "!tmp_extract!"

    :: Extraction avec correction des chemins spéciaux
    echo Extraction de %%~nxz...
    powershell -NoProfile -Command "Expand-Archive -LiteralPath \"%%z\" -DestinationPath \"!tmp_extract!\" -Force"

    :: Suppression des fichiers inutiles
    echo Suppression des fichiers inutiles...
    if exist "!tmp_extract!\final.jpg" del /f /q "!tmp_extract!\final.jpg"
    if exist "!tmp_extract!\ReadMe.txt" del /f /q "!tmp_extract!\ReadMe.txt"

    :: Demande du nom final pour ce ZIP
    set /p "final_name=Nom final pour les fichiers extraits de %%~nxz: "

    echo --- Réindexation et déplacement des fichiers ---
    set /a idx=1

    :: Boucle sur toutes les images, y compris .webp
    for %%f in ("!tmp_extract!\*.png" "!tmp_extract!\*.jpg" "!tmp_extract!\*.jpeg" "!tmp_extract!\*.gif" "!tmp_extract!\*.webp") do (
        if exist "%%f" (
            set "ext=%%~xf"
            set "newfile=!final_name!_!idx!!ext!"

            :: Vérification des conflits
            if exist "%dest_path%\!newfile!" (
                set /a nextnum=1
                :find_free_name
                set "newfile=!final_name!_!idx!(!nextnum!)!ext!"
                if exist "%dest_path%\!newfile!" (
                    set /a nextnum+=1
                    goto find_free_name
                )
                echo Conflit: %%~nxf -> renommé en !newfile!
            )

            move "%%f" "%dest_path%\!newfile!" >nul
            set /a idx+=1
        )
    )

    :: Nettoyage du dossier temporaire
    rd /s /q "!tmp_extract!"
    echo Terminé pour %%~nxz
)

echo.
echo === Tous les ZIP ont été traités ===
pause
