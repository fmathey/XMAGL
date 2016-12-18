#include <XMA/Shapes/TerrainShape.hpp>

struct SDL_Deleter {
    void operator()(SDL_Surface* ptr) { if (ptr) SDL_FreeSurface(ptr); }
};

using SurfacePtr = std::unique_ptr<SDL_Surface,  SDL_Deleter>;

static float getHeightFromImage(int x, int y, SurfacePtr& image)
{
    const int bpp = image->format->BytesPerPixel;
    const Uint8* p = (Uint8*)image->pixels + y * image->pitch + x * bpp;
    return (1.f / 255) * ((int) p[0]);
}

static glm::vec4 getColorFromImage(int x, int y, SurfacePtr& image)
{
    const int bpp = image->format->BytesPerPixel;
    const Uint8* p = (Uint8*)image->pixels + y * image->pitch + x * bpp;

#ifdef XMA_SYSTEM_MACOS
    return glm::vec4(
            (1.f / 255) * ((int) p[2]),
            (1.f / 255) * ((int) p[1]),
            (1.f / 255) * ((int) p[0]),
            1.f
    );
#else
    return glm::vec4(
                (1.f / 255) * ((int) p[0]),
                (1.f / 255) * ((int) p[1]),
                (1.f / 255) * ((int) p[2]),
                1.f
        );
#endif
}

namespace XMA { namespace Shapes {

// ---------------------------------------------------------------------------------------------------------------------

TerrainShape::TerrainShape(
        int resolution,
        const glm::vec3& size,
        const std::string& heigtmapFilename,
        const std::string& colormapFilename
)
{
    SurfacePtr heightmap { nullptr };
    SurfacePtr colormap  { nullptr };

    int hmpRateX { 0 };
    int hmpRateY { 0 };
    int texRateX { 0 };
    int texRateY { 0 };

    XMA_ASSERT(resolution % 8 == 0);

    // Load heightmap

    XMA_ASSERT_FILE_EXISTS(heigtmapFilename);

    heightmap = SurfacePtr(IMG_Load(heigtmapFilename.c_str()));

    XMA_ASSERT(heightmap != nullptr);
    XMA_ASSERT(heightmap->w % 8 == 0 && heightmap->h % 8 == 0);
    XMA_ASSERT(heightmap->w >= resolution && heightmap->h >= resolution);

    hmpRateX =  heightmap->w / resolution;
    hmpRateY =  heightmap->h / resolution;

    // Load colormap if exists

    if(colormapFilename != "") {
        XMA_ASSERT_FILE_EXISTS(colormapFilename);
        colormap = SurfacePtr(IMG_Load(colormapFilename.c_str()));
        XMA_ASSERT(colormap != nullptr);
        XMA_ASSERT(colormap->w % 8 == 0 && colormap->h % 8 == 0);
        XMA_ASSERT(colormap->w >= resolution && colormap->h >= resolution);
        texRateX   =  colormap->w / resolution;
        texRateY   =  colormap->h / resolution;
    }

    glm::vec3 newSize = size;

    if(newSize.x == 0.f) newSize.x = hmpRateX;
    if(newSize.z == 0.f) newSize.z = hmpRateY;

    glm::vec3 scale(newSize.x / resolution, newSize.y, newSize.z / resolution);
    glm::vec3 offset(-(resolution / 2) * scale.x, 0, -(resolution / 2) * scale.z);

    for(auto i(0); i < resolution - 1; i++) {
        for(auto j(0); j < resolution - 1; j++) {

            {
                float y = getHeightFromImage((i + 0) * hmpRateX, (j + 0) * hmpRateY, heightmap);
                vertices.push_back(Vertex(glm::vec3(i + 0.f, y, j + 0.f)));
            }
            {
                float y = getHeightFromImage((i + 0) * hmpRateX, (j + 1) * hmpRateY, heightmap);
                vertices.push_back(Vertex(glm::vec3(i + 0.f, y, j + 1.f)));
            }
            {
                float y = getHeightFromImage((i + 1) * hmpRateX, (j + 1) * hmpRateY, heightmap);
                vertices.push_back(Vertex(glm::vec3(i + 1.f, y, j + 1.f)));
            }
            {
                float y = getHeightFromImage((i + 1) * hmpRateX, (j + 1) * hmpRateY, heightmap);
                vertices.push_back(Vertex(glm::vec3(i + 1.f, y, j + 1.f)));
            }
            {
                float y = getHeightFromImage((i + 1) * hmpRateX, (j + 0) * hmpRateY, heightmap);
                vertices.push_back(Vertex(glm::vec3(i + 1.f, y, j + 0.f)));
            }
            {
                float y = getHeightFromImage((i + 0) * hmpRateX, (j + 0) * hmpRateY, heightmap);
                vertices.push_back(Vertex(glm::vec3(i + 0.f, y, j + 0.f)));
            }

        }
    }

    for(auto i(0u); i < vertices.size(); ++i) {

        indices.push_back(i);

        if(i % 3 == 0) {

            // Generate colors

            if(colormap){
                glm::vec4 color = getColorFromImage(
                        (int) vertices[i+0].position.x * texRateX,
                        (int) vertices[i+0].position.z * texRateY,
                        colormap
                );
                vertices[i+0].color = color;
                vertices[i+1].color = color;
                vertices[i+2].color = color;
            }

            // Resize map

            vertices[i+0].position = (vertices[i+0].position * scale) + offset;
            vertices[i+1].position = (vertices[i+1].position * scale) + offset;
            vertices[i+2].position = (vertices[i+2].position * scale) + offset;

            // Calculate normals

            glm::vec3 u = vertices[i+0].position - vertices[i+1].position;
            glm::vec3 v = vertices[i+0].position - vertices[i+2].position;
            glm::vec3 n = glm::normalize(glm::cross(u, v));

            vertices[i+0].normal = glm::normalize(vertices[i+0].normal + n);
            vertices[i+1].normal = glm::normalize(vertices[i+1].normal + n);
            vertices[i+2].normal = glm::normalize(vertices[i+2].normal + n);
        }
    }

}

// ---------------------------------------------------------------------------------------------------------------------

}}