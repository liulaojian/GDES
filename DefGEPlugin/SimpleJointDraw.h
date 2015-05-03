#pragma once

#include "../MineGEDraw/MineGEDraw.h"

// ��Բ�νڵ����Ч��
class SimpleJointDraw : public MineGEDraw {

public:
	ACRX_DECLARE_MEMBERS(SimpleJointDraw) ;

public:
	SimpleJointDraw () ;
	virtual ~SimpleJointDraw () ;

	virtual void setAllExtraParamsToDefault();
	virtual void configExtraParams();
	virtual void updateExtraParams();

	virtual void readKeyParam(DrawParamReader& reader);
	virtual void writeKeyParam(DrawParamWriter& writer);

	virtual void readExtraParam(DrawParamReader& reader);
	virtual void writeExtraParam(DrawParamWriter& writer);

	virtual void caclBackGroundMinPolygon(AcGePoint3dArray& pts);

protected:
	virtual Adesk::Boolean subWorldDraw (AcGiWorldDraw *mode);

	virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d & xform);

	virtual Acad::ErrorStatus subGetOsnapPoints (
		AcDb::OsnapMode osnapMode,
		Adesk::GsMarker gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds) const ;

	virtual Acad::ErrorStatus subGetGripPoints( 
		AcGePoint3dArray &gripPoints, 
		AcDbIntArray &osnapModes, 
		AcDbIntArray &geomIds ) const;

	virtual Acad::ErrorStatus subMoveGripPointsAt( const AcDbIntArray &indices, const AcGeVector3d &offset );

public:
	// key param
	AcGePoint3d m_insertPt; // ���������
	//double m_angle; // �Ƕ�

	// extra param
	//double m_distance;
	double m_radius; // �뾶
private:
	void drawJoint(AcGiWorldDraw* mode);
} ;

#ifdef DEFGEPLUGIN_MODULE
ACDB_REGISTER_OBJECT_ENTRY_AUTO(SimpleJointDraw)
#endif