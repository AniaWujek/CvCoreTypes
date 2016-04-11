/*!
 * \file
 * \brief
 * \author Anna Wujek
 */

#include <memory>
#include <string>

#include "Drawcircles.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace Drawcircles {

Drawcircles::Drawcircles(const std::string & name) :
		Base::Component(name) , 
		lineColor("lineColor", cv::Scalar(0,255,0)), 
		centerColor("centerColor", cv::Scalar(0,255,0)), 
		thickness("thickness", 3), 
		lineType("lineType", 8), 
		shift("shift", 0) {
	registerProperty(lineColor);
	registerProperty(centerColor);
	registerProperty(thickness);
	registerProperty(lineType);
	registerProperty(shift);

}

Drawcircles::~Drawcircles() {
}

void Drawcircles::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	registerStream("in_img", &in_img);
	registerStream("circles", &circles);
	registerStream("out_img", &out_img);
	// Register handlers
	h_DrawCircles.setup(boost::bind(&Drawcircles::DrawCircles, this));
	registerHandler("DrawCircles", &h_DrawCircles);
	addDependency("DrawCircles", &in_img);
	addDependency("DrawCircles", &circles);

}

bool Drawcircles::onInit() {

	return true;
}

bool Drawcircles::onFinish() {
	return true;
}

bool Drawcircles::onStop() {
	return true;
}

bool Drawcircles::onStart() {
	return true;
}

void Drawcircles::DrawCircles() {
}



} //: namespace Drawcircles
} //: namespace Processors
