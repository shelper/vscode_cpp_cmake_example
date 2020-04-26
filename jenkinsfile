//Adjust your artifactory instance name/repository and your source code repository
// def artifactory_name = "conan-center"
// def artifactory_repo = "conan-local"
// def repo_url = 'https://github.com/memsharded/example-boost-poco.git'
// def repo_branch = 'master'

pipeline {
    def conan_client = Artifactory.newConanClient()

    stage("Get dependencies through conan"){
        sh "mkdir -p build"
        dir ('build') {
          def conan_setup_info = conan_client.run(command: "install .. -b missing")
          server.publishBuildInfo conan_setup_info
        }
    }

    stage("Build project"){
        dir ('build') {
          sh "cmake ../ && cmake --build ."
        }
    }

    // stage("Testing"){
    //     dir ('.'){
    //         sh "CTest"
    //     }
    // }
}