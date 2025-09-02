#include <iostream>
using namespace std;

class DeploymentTarget{
public:
    bool transfer_artifact(string path , string server){
        cout<<"Deployment: transferring "<<path<<" to the server: "<<server<<endl;
        simulate_delay();
        cout<<"Deployment: transferring done..."<<endl;
        return true;
    }

    bool activate_new_version(string server){
        cout<<"Deployment: activating new version on the server: "<<server<<endl;
        simulate_delay();
        cout<<"Deployment: activation complete"<<endl;
        return true;
    }

private:
    void simulate_delay(){
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
};