
# [**ING::ApplicationRenderingSystem**](./..//ING\ApplicationRenderingSystem.md) #
                
## **Basic Info** ##
- `Description` **:** Represents a system of rendering features,...
- `Parent` **:** ING::IApplicationComponent
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **ApplicationRenderingSystem**(ING::IApplication* application) 
                        
                            
- `Destructor` **:**
                
    + **~ApplicationRenderingSystem**() 
                    
                
- `Property` **:**
    
                
    + ING::Rendering::IDevice* **defaultDevice**  **:** the device that the rendering system use it by default
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IDevice* **GetDefaultDevice**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetDefaultDevice**(ING::Rendering::IDevice* newDefaultDevice) 
                                    
                                
    + ING::Rendering::IDevice* **device**  **:** the device that is currently used by the rendering system
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IDevice* **GetDevice**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetDevice**(ING::Rendering::IDevice* newDevice) 
                                    
                                
    + ING::Rendering::IDevice* **targetDevice**  **:** the device that will be used in the next frame
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IDevice* **GetTargetDevice**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetTargetDevice**(ING::Rendering::IDevice* newTargetDevice) 
                                    
                                
    + ING::Rendering::IPipeline* **defaultPipeline**  **:** the pipeline that the rendering system use it by default
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IPipeline* **GetDefaultPipeline**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetDefaultPipeline**(ING::Rendering::IPipeline* newDefaultPipeline) 
                                    
                                
    + ING::Rendering::IPipeline* **pipeline**  **:** the pipeline that is currently used by the rendering system
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IPipeline* **GetPipeline**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetPipeline**(ING::Rendering::IPipeline* newPipeline) 
                                    
                                
    + ING::Rendering::IPipeline* **targetPipeline**  **:** the pipeline that will be used in the next frame
        
                    
        + `Getter` :
                                            
                                
            + ING::Rendering::IPipeline* **GetTargetPipeline**() 
                                    
                                
        + `Setter` :
                                            
                                
            + void **SetTargetPipeline**(ING::Rendering::IPipeline* newTargetPipeline) 
                                    
                                
- `Method` **:**
    
                
    + virtual bool **Init**()  **:** overrided from ING::IApplicationComponent::**Init**()
                        
                    
    + virtual void **Release**()  **:** overrided from ING::IApplicationComponent::**Release**()
                        
                    
    + void **Start**()  **:** overrided from ING::IApplicationComponent::**Start**()
                        
                    
    + void **PreUpdate**()  **:** overrided from ING::IApplicationComponent::**PreUpdate**()
                        
                    
    + void **Update**()  **:** overrided from ING::IApplicationComponent::**Update**()
                        
                    
    + void **LateUpdate**()  **:** overrided from ING::IApplicationComponent::**LateUpdate**()
                        
                    
    + void **PreRender**()  **:** overrided from ING::IApplicationComponent::**PreRender**()
                        
                    
    + void **Render**()  **:** overrided from ING::IApplicationComponent::**Render**()
                        
                    
    + void **LateRender**()  **:** overrided from ING::IApplicationComponent::**LateRender**()
                        
                    