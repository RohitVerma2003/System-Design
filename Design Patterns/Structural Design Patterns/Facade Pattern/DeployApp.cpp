#include "DeploymentFacade.hpp"

class DeployApp{
public:
    static void main(){
        DeploymentFacade deployment_facade;
        deployment_facade.deploy_application("main" , "server.com");
    }
};

int main(){
    DeployApp::main();
    return -1;
}