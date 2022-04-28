
# [**ING::CameraManager**](./..//ING/CameraManager.md) #
                
## **Basic Info** ##
- `Description` **:** Manages cameras
- `Parent` **:** ING::Utils::Singleton < [**ING::CameraManager**](./..//ING/CameraManager.md) > , ING::Utils::Square
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **CameraManager**() 
                        
                            
- `Destructor` **:**
                
    + **~CameraManager**() 
                    
                
- `Property` **:**
    
                
    + List < [**ING::Camera**](./..//ING/Camera.md)* >  **cameraList** 
        
                    
        + `Getter` :
                                            
                                
            + List<[**ING::Camera**](./..//ING/Camera.md)*>& **GetCameraList**() 
                                    
                                
- `Method` **:**
    
                
    + virtual bool **Init**()  **:** overrided from ING::Utils::Square::**Init**()
                        
                    
    + virtual bool **Run**()  **:** overrided from ING::Utils::Square::**Run**()
                        
                    
    + virtual bool **Release**()  **:** overrided from ING::Utils::Square::**Release**()
                        
                    
    + void **Frame Update**()  **:** called every frame
                        
                    
    + void **AddCamera**([**ING::Camera**](./..//ING/Camera.md)* camera)  **:** add a camera for managing
                        
                    
    + void **RemoveCamera**([**ING::Camera**](./..//ING/Camera.md)* camera)  **:** remove a camera that is currently managed
                        
                    