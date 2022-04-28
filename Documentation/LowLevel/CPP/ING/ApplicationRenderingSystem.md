
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
    
                
    + virtual bool **Init**()  **:** overrided from ING::Square::**Init**()
                        
                    
    + virtual bool **Run**()  **:** overrided from ING::Square::**Run**()
                        
                    
    + virtual bool **Release**()  **:** overrided from ING::Square::**Release**()
                        
                    
    + void **Start**()  **:** called when the engine start running, it will call **Start** method of each application
                        
                    
    + void **PreUpdate**()  **:** called before **Update**, it will call **PreUpdate** method of each application
                        
                    
    + void **Update**()  **:** called every frame, it will call **Update** method of each application
                        
                    
    + void **LateUpdate**()  **:** called after **Update**, it will call **LateUpdate** method of each application
                        
                    
    + void **PreRender**()  **:** called before **Render**, it will call **PreRender** method of each application
                        
                    
    + void **Render**()  **:** called when the engine rendering, it will call **Render** method of each application
                        
                    
    + void **LateRender**()  **:** called after **Render**, it will call **LateRender** method of each application
                        
                    
    + void **AddApplication**(ING::IApplication* application)  **:** add an application for managing
                        
                    
    + void **RemoveApplication**(ING::IApplication* application)  **:** remove an application that is currently being managed
                        
                    