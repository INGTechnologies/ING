
# [**ING::Engine**](./..//ING\Engine.md) #
                
## **Basic Info** ##
- `Description` **:** Represents the main engine, manages all engine's systems, managers,...
- `Parent` **:** ING::Utils::Board  <  [**ING::Engine**](./..//ING\Engine.md)  >  [**ING::ApplicationManager**](./..//ING\ApplicationManager.md)
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **Engine**() 
                        
                            
- `Destructor` **:**
                
    + ~**Engine**() 
                    
                
- `Property` **:**
    
                
    + std::string **name** 
        
                    
        + `Getter` :
                                            
                                
            + const std::string& **GetName**() 
                                    
                                
    + std::string **gameDir**  **:** game directory path
        
                    
        + `Getter` :
                                            
                                
            + const std::string& **GetGameDir**() 
                                    
                                
    + std::wstring **gameDir_wstr**  **:** game directory path in wide string
        
                    
        + `Getter` :
                                            
                                
            + const std::string& **GetGameDir_WSTR**() 
                                    
                                
    + std::string **workingDir**  **:** current working directory path
        
                    
        + `Getter` :
                                            
                                
            + const std::string& **GetWorkingDir**() 
                                    
                                
    + std::wstring **workingDir_wstr**  **:** current working directory path in wide string
        
                    
        + `Getter` :
                                            
                                
            + const std::string& **GetWorkingDir_WSTR**() 
                                    
                                
    + std::unordered_map < std::wstring, std::wstring >  **rootPath2AbsolutePath**  **:** root path to absolute path map
        
                    
        + `Item Getters` :
                                    
                                
            + const std::wstring& **GetRootPath**(const std::wstring& rootPath)  **:** get the value of root path
                                    
                                
            + bool **IsHaveRootPath**(const std::wstring& rootPath)  **:** check if engine has 'rootPath' root path
                                    
                                
        + `Item Setter` :
                                            
                                
            + void **SetRootPath**(const std::wstring& name, const std::wstring& value)  **:** set the value of root path by name and value
                                    
                                
    + ING::EngineState **state** 
        
                    
        + `Getter` :
                                            
                                
            + ING::EngineState **GetState**() 
                                    
                                
    + ING::Configuration* **configuration** 
        
                    
        + `Getter` :
                                            
                                
            + ING::Configuration* **GetConfiguration**() 
                                    
                                
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
                    
+ [**ING::ApplicationManager**](./..//ING\ApplicationManager.md)
                        
                    