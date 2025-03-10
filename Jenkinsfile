pipeline {
    agent any

    environment {
        ARDUINO_CLI = ""C:\Program Files\Arduino CLI\arduino-cli.exe"
        BOARD_FQBN = "arduino:avr:uno"
        SKETCH_DIR = "C:\\Users\\Jenkins\\workspace\\IoT-Pipeline-Jenkins"  // Adjust the path
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: 'https://github.com/Soham-1808/IoT-Pipeline-Jenkins.git'
            }
        }

        stage('Setup Arduino CLI') {
            steps {
                bat """
                %ARDUINO_CLI% core update-index
                %ARDUINO_CLI% core install arduino:avr
                """
            }
        }

        stage('Verify Code') {
            steps {
                bat "%ARDUINO_CLI% compile --fqbn %BOARD_FQBN% %SKETCH_DIR%"
            }
        }

        stage('Upload to Arduino') {
            steps {
                bat """
                for /f "tokens=1 delims= " %%A in ('%ARDUINO_CLI% board list ^| findstr /C:"COM"') do set PORT=%%A
                if "%PORT%"=="" (
                  echo No Arduino board detected!
                  exit /b 1
                )
                %ARDUINO_CLI% upload --fqbn %BOARD_FQBN% --port %PORT% %SKETCH_DIR%
                """
            }
        }
    }

    post {
        success {
            echo "✅ Deployment successful!"
        }
        failure {
            echo "❌ Build failed!"
        }
    }
}
