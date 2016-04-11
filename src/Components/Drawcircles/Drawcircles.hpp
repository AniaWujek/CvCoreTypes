/*!
 * \file
 * \brief 
 * \author Anna Wujek
 */

#ifndef DRAWCIRCLES_HPP_
#define DRAWCIRCLES_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"

#include <opencv2/opencv.hpp>


namespace Processors {
namespace Drawcircles {

/*!
 * \class Drawcircles
 * \brief Drawcircles processor class.
 *
 * 
 */
class Drawcircles: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	Drawcircles(const std::string & name = "Drawcircles");

	/*!
	 * Destructor
	 */
	virtual ~Drawcircles();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	// Input data streams
	Base::DataStreamIn<cv::Mat> in_img;
	Base::DataStreamIn<Types::Circles> circles;

	// Output data streams
	Base::DataStreamOut<cv::Mat> out_img;

	// Handlers
	Base::EventHandler2 h_DrawCircles;

	// Properties
	Base::Property<cv::Scalar> lineColor;
	Base::Property<cv::Scalar> centerColor;
	Base::Property<int> thickness;
	Base::Property<int> lineType;
	Base::Property<int> shift;

	
	// Handlers
	void DrawCircles();

};

} //: namespace Drawcircles
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("Drawcircles", Processors::Drawcircles::Drawcircles)

#endif /* DRAWCIRCLES_HPP_ */
