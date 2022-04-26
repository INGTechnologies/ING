# ING Engine Overview #

## Board and Square ##
+ Board is 1 class, singleton and have it own squares, virtual methods:
    - bool Init()
    - bool Run()
    - bool Release()
+ Square is 1 class and have virtual methods:
    - bool Init()
    - bool Run()
    - bool Release()
+ We use Board and Square as "Low Level Modules". ING::Engine is 1 class inherited Board class