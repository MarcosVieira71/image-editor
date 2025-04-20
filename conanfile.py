from conan import ConanFile

class EditorImagem(ConanFile):
    generators = ("CMakeToolchain", "CMakeDeps")
    settings = ("os", "build_type")

    def requirements(self):
        self.requires("sfml/2.6.2")
        self.requires("imgui/1.91.8")
        self.requires("imgui-sfml/2.6.1")
        self.requires("qt/6.7.3")
    
    def build_requirements(self):
        self.tool_requires("cmake/[>=3.25]")
    
    def configure(self):
        self.options["qt"].qttools = True
        self.options["qt"].xcb = True
        self.options["qt"].shared = True

