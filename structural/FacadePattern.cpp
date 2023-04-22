#include <iostream>
#include <vector>
#include <string>

class DeviceFacade{

  public: virtual void write(const std::string& data) = 0 ;
  public: virtual std::string read() = 0 ;
  public: virtual ~DeviceFacade(){}
};


class DeviceGeneric : public DeviceFacade{

public: void write(const std::string& datparamDataa){
   std::cout <<"WRITE DEVICE\n" << datparamDataa ;

}

public: std::string read(){
   return "READ DEVICE\n" ;

}

   
};


class ManagerDeviceFacade {

   private : std::vector<DeviceFacade*> devices;

   public : ManagerDeviceFacade(){
      devices.push_back(new DeviceGeneric());
   }

   ~ManagerDeviceFacade(){

      for(int i = 0 ; i <= devices.size(); i++){
         delete devices[i];
      }
   }

void addDevice(int deviceIndex , const std::string& data){

   devices[deviceIndex]->write(data);   
}

std::string executeDevice(int deviceIndex){

   return devices[deviceIndex]->read();
}


   
};

int main(){


  DeviceFacade* mouseUSB = new DeviceGeneric();
  DeviceGeneric generic ;
  ManagerDeviceFacade* managerDeviceFacade = new ManagerDeviceFacade();


  generic.write("TESTE PARAM");
  generic.read();
  std::cout <<"\n";

  
  managerDeviceFacade->addDevice(0 ,"deviceGeneric");
  managerDeviceFacade->executeDevice(0);
  std::cout <<"\n";

  
  mouseUSB->write("MOBILE");
  mouseUSB->read();

  
   return 0; 
}