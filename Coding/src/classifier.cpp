#define TINYCOLORMAP_WITH_EIGEN
#include "tinycolormap.hpp"
#include "classifier.hpp"
#include "constant.hpp"
#include "utils.hpp"


/**
 * IsosurfaceClassifier class
 */

IsosurfaceClassifier::IsosurfaceClassifier(float isoval)
    : isovalue(isoval)
{
}

OpticsData IsosurfaceClassifier::transfer(VolumePointData v_data, Camera *cam, const std::vector<Light*>& lights, float dt) const
{
    OpticsData optics;

    // TODO
    UNREACHABLE;

    return optics;
}

