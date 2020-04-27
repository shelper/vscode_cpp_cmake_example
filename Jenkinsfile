//Adjust your artifactory instance name/repository and your source code repository
// def artifactory_name = "conan-center"
// def artifactory_repo = "conan-local"
// def repo_url = 'https://github.com/memsharded/example-boost-poco.git'
// def repo_branch = 'master'

pipeline {
  agent any
  stages {
      stage("conan install"){
        steps {
          sh "mkdir -p build"
          dir ('build') {
            sh "conan install .. -b missing"
          }
        }
      }
      stage("cmake config"){
        steps {
          dir ('build') {
            sh "cmake .."
          }
        }
      }
      stage("building...") {
        steps {
          dir ('build') {
            sh "cmake --build ."
          }
        }
      }
      // stage("Testing"){
      //     dir ('.'){
      //         sh "CTest"
      //     }
      // }
  }
}