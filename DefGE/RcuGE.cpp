#include "StdAfx.h"
#include "RcuGE.h"

Adesk::UInt32 RcuGE::kCurrentVersionNumber = 1 ;
Adesk::UInt32 RcuTagGE::kCurrentVersionNumber = 1 ;

ACRX_NO_CONS_DEFINE_MEMBERS(RcuGE, MineGE)
ACRX_NO_CONS_DEFINE_MEMBERS(RcuTagGE, TagGE)

RcuGE::RcuGE()
{

}

Acad::ErrorStatus RcuGE::dwgOutFields ( AcDbDwgFiler* pFiler ) const
{
    assertReadEnabled () ;
    //----- Save parent class information first.
    Acad::ErrorStatus es = MineGE::dwgOutFields ( pFiler ) ;
    if ( es != Acad::eOk )
        return ( es ) ;
    //----- Object version number needs to be saved first
    if ( ( es = pFiler->writeUInt32 ( RcuGE::kCurrentVersionNumber ) ) != Acad::eOk )
        return ( es ) ;

    return ( pFiler->filerStatus () ) ;
}

Acad::ErrorStatus RcuGE::dwgInFields ( AcDbDwgFiler* pFiler )
{
    assertWriteEnabled () ;
    //----- Read parent class information first.
    Acad::ErrorStatus es = MineGE::dwgInFields ( pFiler ) ;
    if ( es != Acad::eOk )
        return ( es ) ;
    //----- Object version number needs to be read first
    Adesk::UInt32 version = 0 ;
    if ( ( es = pFiler->readUInt32 ( &version ) ) != Acad::eOk )
        return ( es ) ;
    if ( version > RcuGE::kCurrentVersionNumber )
        return ( Acad::eMakeMeProxy ) ;

    return ( pFiler->filerStatus () ) ;
}


RcuTagGE::RcuTagGE()
{

}

Acad::ErrorStatus RcuTagGE::dwgOutFields ( AcDbDwgFiler* pFiler ) const
{
	assertReadEnabled () ;
	//----- Save parent class information first.
	Acad::ErrorStatus es = TagGE::dwgOutFields ( pFiler ) ;
	if ( es != Acad::eOk )
		return ( es ) ;
	//----- Object version number needs to be saved first
	if ( ( es = pFiler->writeUInt32 ( RcuTagGE::kCurrentVersionNumber ) ) != Acad::eOk )
		return ( es ) ;

	return ( pFiler->filerStatus () ) ;
}

Acad::ErrorStatus RcuTagGE::dwgInFields ( AcDbDwgFiler* pFiler )
{
	assertWriteEnabled () ;
	//----- Read parent class information first.
	Acad::ErrorStatus es = TagGE::dwgInFields ( pFiler ) ;
	if ( es != Acad::eOk )
		return ( es ) ;
	//----- Object version number needs to be read first
	Adesk::UInt32 version = 0 ;
	if ( ( es = pFiler->readUInt32 ( &version ) ) != Acad::eOk )
		return ( es ) ;
	if ( version > RcuTagGE::kCurrentVersionNumber )
		return ( Acad::eMakeMeProxy ) ;

	return ( pFiler->filerStatus () ) ;
}