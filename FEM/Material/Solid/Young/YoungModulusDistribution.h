/**
 * \copyright
 * Copyright (c) 2012-2017, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 *  \author Wenqing Wang
 *  \file   PorosityDependentFractureRockPermeability.h
 *  Created on July 2, 2018, 10:23 AM
 */

#pragma once

#include <vector>
#include <string>

namespace MeshLib
{
class CFEMesh;
}
namespace MaterialLib
{
class YoungModulusDistribution
{
public:
	YoungModulusDistribution(const std::string& file_name, const MeshLib::CFEMesh& mesh);

	double getYoungsModulus(const int element_id) {
		return _young[element_id];
	}

private:
	std::vector<double> _young; /// Element wise value.
};
} // End of name space
