#include <omp.h>
#include "optics_data.hpp"
#include "volume_renderer.hpp"
#include "config.hpp"


extern Config conf;

/**
 * VolumeRenderer class
 */

VolumeRenderer::VolumeRenderer()
    : camera(NULL)
    , classifier(NULL)
    , geom(NULL)
{
}

void VolumeRenderer::setCamera(Camera* cam)
{
    camera = cam;
}

void VolumeRenderer::addLight(Light* li)
{
    lights.push_back(li);
}

void VolumeRenderer::setGeometry(ImplicitGeometry* implicit_geom)
{
    geom = implicit_geom;
}

void VolumeRenderer::setClassifier(Classifier* cls)
{
    classifier = cls;
}

void VolumeRenderer::renderFrontToBack()
{
    int res_x = camera->getFilm().resolution.x();
    int res_y = camera->getFilm().resolution.y();
    float dt = conf.step_len;

#ifndef NO_OMP
    #pragma omp parallel for
#endif
    for (int i = 0; i < res_x * res_y; ++i)
    {
        int dy = i / (float)res_x;
        int dx = i - dy * (float)res_x;
        Ray ray = camera->generateRay((float)dx, (float)dy);
        Eigen::Vector3f color(0, 0, 0);
        Eigen::Vector3f alpha(0, 0, 0);
        
        // TODO
        UNREACHABLE;

        camera->setPixel(dx, dy, color);
    }
};
