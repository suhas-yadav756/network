@echo off
echo Downloading Network Programs...

curl -L https://github.com/suhas-yadav756/network/archive/refs/heads/main.zip -o network.zip

powershell -Command "Expand-Archive -Force network.zip ."

echo.
echo Download and extraction completed successfully!
pause