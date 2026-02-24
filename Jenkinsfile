pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                bat 'cmake -B build -S .'
                bat 'cmake --build build --config Debug'
            }
        }
        stage('Test') {
            steps {
                // Run tests
                bat 'build\\Debug\\run_tests.exe'
            }
        }
    }
}