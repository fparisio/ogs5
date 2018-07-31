/**
 * \copyright
 * Copyright (c) 2012-2018, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 *  \author Wenqing Wang
 *  \file   YoungModulus.cpp
 *  Created on July 2, 2018, 10:23 AM
 */

#include "YoungModulus.h"

#include <iostream>
#include <fstream>
#include <cmath>

#include "msh_mesh.h"

namespace MaterialLib
{
YoungModulusDistribution::YoungModulusDistribution(const std::string& file_name, const MeshLib::CFEMesh& mesh)
{
	std::ifstream inf(file_name.data());
	if (!inf.good())
	{
		std::cout << "File " << file_name << " for YoungModulusDistribution (type 9) "
		          << " is not found";
		exit(EXIT_FAILURE);
	}

	inf >> std::ws;
	while (!inf.eof())
	{
		double val;
		inf >> val >> std::ws;
		_young.push_back(val);
	}

	if (_young.size() != mesh.getElementVector().size())
	{
		std::cout << "The number of data in file " << file_name << " is not identical to the number of elements";
		exit(EXIT_FAILURE);
	}
}

} // End of name space
