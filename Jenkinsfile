 node {
   stage('Checkout')
   // NO-OP
 }
 podTemplate(name: 'cpp', label: 'cpp', cloud: 'openshift', idleMinutes: 60, containers: [
   containerTemplate(
       name: 'jnlp',
       image: 'docker-registry.default.svc:5000/openshift/cpp-slave',
       alwaysPullImage: true,
       args: '${computer.jnlpmac} ${computer.name}',
       ttyEnabled: false,
       privileged: false,
       workingDir: '/tmp/jenkins')]
  ) {
 node('cpp') {
   stage('Build') {
     sh 'cmake .'
     make 'test'
     sh 'doxygen -g'
     sh 'doxygen Doxyfile'
     publishHTML(target: [allowMissing: false, alwaysLinkToLastBuild: false, keepAll: true, reportDir: 'html', reportFiles: 'index.html', reportName: 'Code Documentation'])
    }
   }
 }
