from conan import ConanFile

class EditorImagem(ConanFile):
    generators = ("CMakeToolchain", "CMakeDeps")
    settings = ("os", "build_type")

    def requirements(self):
        self.requires("sfml/2.6.2")
        self.requires("imgui/1.91.8")
        self.requires("imgui-sfml/2.6.1")
    
    def build_requirements(self):
        self.tool_requires("cmake/[>=3.25]")