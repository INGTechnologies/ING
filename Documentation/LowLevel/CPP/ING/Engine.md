
# [**ING::Engine**](./..//ING/Engine.md) #
                
## **Basic Info** ##
- `Description` **:** Represents the main engine, manages all engine's systems, managers,...
- `Parent` **:** ING::Utils::Board  <  [**ING::Engine**](./..//ING/Engine.md)  >  [**ING::ApplicationManager**](./..//ING/ApplicationManager.md)
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **Engine**() 
                        
                            
- `Destructor` **:**
                
    + ~**Engine**() 
                    
                
- `Property` **:**
    
                
    + ING::Utils::String **name** 
        
                    
        + `Getter` :
                                            
                                
            + const ING::Utils::String& **GetName**() 
                                    
                                
    + ING::Utils::String **gameDir**  **:** game directory path
        
                    
        + `Getter` :
                                            
                                
            + const ING::Utils::String& **GetGameDir**() 
                                    
                                
    + ING::Utils::WString **gameDir_wstr**  **:** game directory path in wide string
        
                    
        + `Getter` :
                                            
                                
            + const ING::Utils::String& **GetGameDir_WSTR**() 
                                    
                                
    + ING::Utils::String **workingDir**  **:** current working directory path
        
                    
        + `Getter` :
                                            
                                
            + const ING::Utils::String& **GetWorkingDir**() 
                                    
                                
    + ING::Utils::WString **workingDir_wstr**  **:** current working directory path in wide string
        
                    
        + `Getter` :
                                            
                                
            + const ING::Utils::String& **GetWorkingDir_WSTR**() 
                                    
                                
    + std::unordered_map < ING::Utils::WString, ING::Utils::WString >  **rootPath2AbsolutePath**  **:** root path to absolute path map
        
                    
        + `Item Getters` :
                                    
                                
            + const ING::Utils::WString& **GetRootPath**(const ING::Utils::WString& rootPath)  **:** get the value of root path
                                    
                                
            + bool **IsHaveRootPath**(const ING::Utils::WString& rootPath)  **:** check if engine has 'rootPath' root path
                                    
                                
        + `Item Setter` :
                                            
                                
            + void **SetRootPath**(const ING::Utils::WString& name, const ING::Utils::WString& value)  **:** set the value of root path by name and value
                                    
                                
    + ING::EngineState **state** 
        
                    
        + `Getter` :
                                            
                                
            + ING::EngineState **GetState**() 
                                    
                                
    + [**ING::Configuration**](./..//ING/Configuration.md)* **configuration** 
        
                    
        + `Getter` :
                                            
                                
            + [**ING::Configuration**](./..//ING/Configuration.md)* **GetConfiguration**() 
                                    
                                
- `Method` **:**
    
                
    + void **FrameUpdate**()  **:** called every frame
                        
                            
## **Macros** ##
                    
+ **ING_CREATE_ENGINE**  **:** to create the engine
                        
                    
+ **ING_INIT_ENGINE**  **:** to init the engine
                        
                    
+ **ING_RUN_ENGINE**  **:** to run the engine
                        
                    
+ **ING_ENGINE_CONFIG_PROP**(T, name, value)  **:** try add new engine configuration property
                        
                    
+ **ING_ENGINE_SET_CONFIG_PROP**(T, name, value)  **:** set engine configuration property
                        
                    
+ **ING_ENGINE_GET_CONFIG_PROP**(T, name)  **:** get engine configuration property
                        
                            
## **Square** ##
                    
+ [**ING::ApplicationManager**](./..//ING/ApplicationManager.md)
                        
                    