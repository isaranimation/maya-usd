//
// Copyright 2018 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include <basePxrUsdPreviewSurface/usdPreviewSurfacePlugin.h>

#include <maya/MFnPlugin.h>
#include <maya/MString.h>

#include "api.h"

PXR_NAMESPACE_USING_DIRECTIVE

PXRUSDPREVIEWSURFACE_API
MStatus
initializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj, "Pixar", "1.0", "Any");
    
    status = PxrMayaUsdPreviewSurfacePlugin::initialize(plugin);
    CHECK_MSTATUS(status);

    return MS::kSuccess;
}

PXRUSDPREVIEWSURFACE_API
MStatus
uninitializePlugin(MObject obj)
{
    MStatus status;
    MFnPlugin plugin(obj);
    
    status = PxrMayaUsdPreviewSurfacePlugin::finalize(plugin);
    CHECK_MSTATUS(status);

    return MS::kSuccess;
}
