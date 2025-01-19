================================================================================================================================

Vulkan Instance, Devices, Extensions, Validation layers

================================================================================================================================

i. Vulkan applications start by making a vulkan instance
ii. Enumerate physical devices to find a GPU
iii. Create logical device to interface with the physical device
iv. Multiple types of queues (queue families) can be assigned on logical device
v. Extensions can be applied
vi. We use GLFW to create our window and determine the proper extensions required
vii. validation layers are optional, but neccessary. Vulkan does not error check code by default to ensure high performance

================================================================================================================================

Vulkan Instance : A vulkan instance is a reference to the vulkan context
    a. Always is the first thing we create
    b. Defines vulkan version and its capabilities
    c. From vulkan instances we create other things
    d. Instances are rarely used after first created
    e. When we create our instance we enumerate over phyiscal devices

Device: Vulkan recognizes two kings of devices
    a. Phyiscal Device
    b. Logical Device

Physical Device: The GPU on your machine
    a. Can't be interacted with directly
    b. Contains memory queues
        i. Process commands to GPU in FIFO (First in first out) order
        ii. Different queues can be used for different commands
    c. Retrived NOT created!
    d. Physical devices can have multiple types of queues  referred as queue family
        i. A family has multiple queues
            - Graphics family
            - Compute familty
            - Transfer queue family
            - ...

Logical Device: An interface to the physical device
    a. Will be used a lot in vulkan functions
    b. Most vulkan objects are created on this device
    c. Creation APPARENTLY is simple 
        i. defines a family of queues
        ii. defines all features you wish to use
        iii. defines all extensions you wish to use

Extensions
    a. Vulkan has no idea what a window is
        i. This is because it is cross platform and different platforms define windows differently.
    b. extensions add window functionality
    c. GLFW library has a function to choose what extension to use
        i. this is better because it is extremely complicated to calculate what extensions to use by yourself

GLFW: Graphics library framework
    a. cross platform
    b. has a function to determine which extension to use
    c. glfwGetRequiredInstanceExtensions()
        i. returns a list of all extensions we need
        ii. then we can pass this to set up a vulkan instance
        iii. this bypasses hundreds of lines of code!

Validation Layers

    VK_LAYER_LUNARG_standard_validation is a common all round layer
    used often when first starting out.

    a. By default vulkan does not validate code errors.
        i. Things will act strange instead of error out
        ii. This is due to optimization. If it checked everything, it would be a lot slower because there is so much to check.
    b. Validation layer is something we can enable to check
    c. Each layer can check different function names
    d. Validation layers are often installed as extensions by 3rd parties, but there are some layers that come with the Vulkan SDK
    e. By default these layers do not directly print the error messages. (WOW)
        i. To get past this issue we need an addtional extension.
