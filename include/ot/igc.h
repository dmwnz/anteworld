#pragma once

#ifndef __INTERGEN_GENERATED__igc_H__
#define __INTERGEN_GENERATED__igc_H__

//@file Interface file for igc interface generated by intergen
//See LICENSE file for copyright and license information

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include <ot/glm/glm_meta.h>
#include <ot/igc_data.h>

class app;


namespace ot {

////////////////////////////////////////////////////////////////////////////////
///OT IGC (image generator control) interface //////////////////////////////
class igc
    : public intergen_interface
{
public:

    // --- interface methods ---

    ///Set camera position
    //@param ecef position in ECEF coordinates
    //@param rot camera rotation into OT view space (-z forward, +y up, +x side)
    void set_pos( const double3& ecef, const quat& rot );

    ///Get current camera position in ECEF
    const double3& pos();

    ///Get current camera rotation in OT view space (-z forward, +y up, +x side)
    const quat& rot();

    ///Get info about current position & speed
    void info( ifc_out ot::igc_data& data );

    ///Test intesection of ray with terrain
    //@return >= 0 intersection distance, <0 for no intersect
    //@param from starting position of the ray to test
    //@param to ending position of the ray to test, note: keep the ray as short as possible
    //@param pos surface position at the intersecting point
    //@param norm surface normal at the intersection
    //@param dist distance from the starting point to intersection
    double intersect( const double3& from, const double3& to, ifc_out double3& pos, ifc_out float3& norm );

    ///Set world time for current location
    //@param dyear day of year
    //@param tday solar time of day
    //@param flowm time flow multiplier, 1.0 normal time flow
    void set_time( int64 dyear, double tday, float flowm = 1.0f );


protected:
    // --- interface events (callbacks from host to client) ---
    // ---       overload these to handle host events       ---

    friend class ::app;

    ///Event invoked before rendering frame
    //@param time the current game time for the frame
    virtual void update( double time ) {}

    virtual void force_bind_script_events() {}

public:
    // --- host helpers to check presence of handlers in scripts ---

    virtual bool is_bound_update() { return true; }
    
public:
    // --- creators ---

    static iref<igc> get() {
        return get<igc>(0);
    }

    template<class T>
    static iref<T> get( T* _subclass_ );

    // --- internal helpers ---

    virtual ~igc() {
        if(_cleaner) _cleaner(this,0);
    }

    static const int HASHID = 3989578598;

    int intergen_hash_id() const override final { return HASHID; }
    
    bool iface_is_derived( int hash ) const override final {
        return hash == HASHID;
    }

    const coid::tokenhash& intergen_interface_name() const override final {
        static const coid::tokenhash _name = "ot::igc";
        return _name;
    }

    static const coid::token& intergen_default_creator_static( EBackend bck ) {
        static const coid::token _dc("ot::igc.get@3989578598");
        static const coid::token _djs("ot::js::igc@wrapper");
        static const coid::token _dnone;

        switch(bck) {
        case IFC_BACKEND_CXX: return _dc;
        case IFC_BACKEND_JS:  return _djs;
        default: return _dnone;
        }
    }


    template<enum EBackend B>
    static void* intergen_wrapper_cache() {
        static void* _cached_wrapper=0;
        if(!_cached_wrapper) {
            const coid::token& tok = intergen_default_creator_static(B);
            _cached_wrapper = coid::interface_register::get_interface_creator(tok);
        }
        return _cached_wrapper;
    }
    
    void* intergen_wrapper( EBackend bck ) const override final {
        switch(bck) {
        case IFC_BACKEND_JS: return intergen_wrapper_cache<IFC_BACKEND_JS>();
        default: return 0;
        }
    }
    
    EBackend intergen_backend() const override { return IFC_BACKEND_CXX; }
    
    const coid::token& intergen_default_creator( EBackend bck ) const override final {
        return intergen_default_creator_static(bck);
    }

protected:

    typedef void (*cleanup_fn)(igc*, intergen_interface*);
    cleanup_fn _cleaner;

    igc() : _cleaner(0)
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> igc::get( T* _subclass_ )
{
    typedef iref<T> (*fn_creator)(igc*);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::igc.get@3989578598";

    if(!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if(!create)
        throw coid::exception("interface creator inaccessible: ") << ifckey;

    return create(_subclass_);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline void igc::set_pos( const double3& ecef, const quat& rot )
{ return VT_CALL(void,(const double3&,const quat&),0)(ecef,rot); }

inline const double3& igc::pos()
{ return VT_CALL(const double3&,(),1)(); }

inline const quat& igc::rot()
{ return VT_CALL(const quat&,(),2)(); }

inline void igc::info( ot::igc_data& data )
{ return VT_CALL(void,(ot::igc_data&),3)(data); }

inline double igc::intersect( const double3& from, const double3& to, double3& pos, float3& norm )
{ return VT_CALL(double,(const double3&,const double3&,double3&,float3&),4)(from,to,pos,norm); }

inline void igc::set_time( int64 dyear, double tday, float flowm )
{ return VT_CALL(void,(int64,double,float),5)(dyear,tday,flowm); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__igc_H__
