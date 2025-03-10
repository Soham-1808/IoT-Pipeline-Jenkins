pipeline { 
    agent any 
 
    environment { 
        ARDUINO_CLI = "C:\\Program Files\\Arduino CLI\\arduino-cli.exe" 
        ARDUINO_DATA_PATH = "C:\\arduino-project" 
    } 
 
    stages { 
        stage('Checkout Code') { 
            steps {*; 
                git branch: 'main', url: 'https://github.com/Soham-1808/IoT-Pipeline-Jenkins.git' 
            } 
        } 
 
        stage('Setup Environment') { 
            steps { 
                bat 'set ARDUINO_DATA_PATH=C:\\arduino-project' 
                bat "\"%ARDUINO_CLI%\" core update-index" 
                bat "\"%ARDUINO_CLI%\" core install arduino:avr" 
            } 
        } 
 
        stage('Compile Sketch') { 
            steps { 
                bat "\"%ARDUINO_CLI%\" compile --fqbn arduino:avr:uno ." 
            } 
        } 
 
        stage('Build Successful') { 
            steps { 
                echo 'Build completed successfully!' 
            } 
        } 
    } 
} 