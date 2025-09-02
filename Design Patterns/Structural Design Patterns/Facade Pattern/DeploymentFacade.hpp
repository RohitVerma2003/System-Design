#include <iostream>
#include "VCS.hpp"
#include "BuildSystem.hpp"
#include "TestingSystem.hpp"
#include "DeploymentTarget.hpp"
using namespace std;

class DeploymentFacade{
private:
    VCS vcs;
    BuildSystem build_system;
    TestingSystem testing_system;
    DeploymentTarget deploy_target;
public:
    bool deploy_application(string branch , string server){
        cout<<"FACADE: Initiating the deployment process..."<<endl;
        bool success = true;

        try{
            this->vcs.pull_current_branch(branch);

            string artifact_path = this->build_system.artifact_path();
            if(!this->build_system.compile_project()){
                cerr<<"Build Failed."<<endl;
                success = false;
            }
            
            if(!this->testing_system.unit_testing() || !this->testing_system.integration_testing()){
                cerr<<"Testing Failed."<<endl;
                success = false;
            }

            this->deploy_target.transfer_artifact(artifact_path , server);
            this->deploy_target.activate_new_version(server);

            cout<<"FACADE: Application deployed successfully..."<<endl;
        }catch(const std::exception& e){
            cerr << "FACADE: DEPLOYMENT FAILED - An unexpected error occurred: " << e.what() << endl;
            success = false;
        }
        
        return success;
    }
};