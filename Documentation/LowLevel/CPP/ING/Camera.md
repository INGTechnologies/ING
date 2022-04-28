
# [**ING::Camera**](./..//ING\Camera.md) #
                
## **Basic Info** ##
- `Description` **:** a device through which the player views the world
- `Parent` **:** None
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **Camera**() 
                        
                            
- `Destructor` **:**
                
    + **~Camera**() 
                    
                
- `Property` **:**
    
                
    + ING::List < [**ING::Camera**](./..//ING\Camera.md)* > ::Node* **node**  **:** the node in the camera list of ING::CameraManager
        
                    
        + `Getter` :
                                            
                                
            + ING::List<[**ING::Camera**](./..//ING\Camera.md)*>::Node* **GetNode**() 
                                    
                                
    + ING::List < [**ING::Camera**](./..//ING\Camera.md)* > ::Node* **nodeInScreenCameraList**  **:** the node in the camera list of screen
        
                    
        + `Getter` :
                                            
                                
            + ING::List<[**ING::Camera**](./..//ING\Camera.md)*>::Node* **GetNodeInScreenCameraList**() 
                                    
                                
    + ING::CameraId* **id** 
        
                    
        + `Getter` :
                                            
                                
            + ING::CameraId **GetId**() 
                                    
                                
    + bool **isActive** 
        
                    
        + `Getter` :
                                            
                                
            + bool **IsActive**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetActive**(bool isActive) 
                                    
                                
    + ING::Math::RMatrix4x4 **viewMatrix** 
        
                    
        + `Getter` :
                                            
                                
            + const ING::Math::RMatrix4x4& **GetViewMatrix**() 
                                    
                                
    + ING::Math::RMatrix4x4 **projectionMatrix** 
        
                    
        + `Getter` :
                                            
                                
            + const ING::Math::RMatrix4x4& **GetProjectionMatrix**() 
                                    
                                
    + ING::TransformM **transformM** 
        
                    
        + `Getter` :
                                            
                                
            + const ING::TransformM& **GetTransformM**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetTransformM**(const ING::TransformM& newTransformM) 
                                    
                                
    + float **farPlane** 
        
                    
        + `Getter` :
                                            
                                
            + float **GetFarPlane**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetFarPlane**(float newFarPlane) 
                                    
                                
    + float **nearPlane** 
        
                    
        + `Getter` :
                                            
                                
            + float **GetNearPlane**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetNearPlane**(float newNearPlane) 
                                    
                                
    + float **farPlane** 
        
                    
        + `Getter` :
                                            
                                
            + float **GetFarPlane**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetFarPlane**(float newFarPlane) 
                                    
                                
    + ING::Screen* **screen** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Screen* **GetScreen**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetScreen**(ING::Screen* newScreen) 
                                    
                                
    + unsigned int **oldScreenWidth** 
        
                    
    + unsigned int **oldScreenHeight** 
        
                    
    + ING::Rendering::Scene* **renderingScene** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::Scene* **GetRenderingScene**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetRenderingScene**(ING::Rendering::Scene* newScene) 
                                    
                                
    + ING::Rendering::ICameraData* **renderingData** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::ICameraData* **GetRenderingData**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetRenderingData**(ING::Rendering::ICameraData* newData) 
                                    
                                
    + ING::Rendering::IPipeline* **renderingPipeline** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IPipeline* **GetRenderingPipeline**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetRenderingPipeline**(ING::Rendering::IPipeline* newPipeline) 
                                    
                                
    + ING::CameraTargetMode **targetMode** 
        
                    
        + `Getter` :
                                            
                                
            + CameraTargetMode **GetTargetMode**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetTargetMode**(CameraTargetMode newTargetMode) 
                                    
                                
- `Method` **:**
    
                
    + void **Update**()  **:** called every frame
                        
                    
    + unsigned int **GetClientWidth**()  **:** get screen's window client width
                        
                    
    + unsigned int **GetClientHeight**()  **:** get screen's window client height
                        
                    