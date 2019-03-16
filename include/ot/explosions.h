#pragma once

#ifndef __INTERGEN_GENERATED__explosions_H__
#define __INTERGEN_GENERATED__explosions_H__

//@file Interface file for explosions interface generated by intergen
//See LICENSE file for copyright and license information

//host class: ::tracer

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

#include <ot/explosion_params.h>

class tracer;


namespace ot {

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///Tracer & explosion interface
class explosions
    : public intergen_interface
{
public:

    // --- interface methods ---

    uint launch_combo( const double3& pos, const float3& speed, float size, const float3& color, const float3& smoke_color, float emitter_radius, float emitter_speed, float particle_size, float smoke_timeout, bool crater, bool solids, bool smoke );

    ///Launch a ballistic tracer that will create an explosion on impact
    //@return trace id
    //@param pos launch position
    //@param speed launch speed vector
    //@param size tracer size
    //@param color tracer color
    //@param fadeout emission reduction parameter for each older point on the trail
    //@param trail length of the trail in seconds
    //@param timeout time [s] of tracer existence: <=0 means until hitting the ground
    //@param age age of the tracer. Affects trail length, fall speed.
    //@param tracer_id tracer id to reuse
    //@param entid object id to be dragged by tracer
    //@param uservalue custom value
    uint launch_tracer( const double3& pos, const float3& speed, float size, const float3& color, float fadeout = 0.5f, float trail = 0.2f, float timeout = 0.0f, float age = 0, uint tracer_id = UMAX32, uint entid = UMAX32, uint uservalue = 0 );

    void flash( const double3& pos, float intensity, const float4& color, float range, float timeout );

    ///Get array of landed tracers
    const coid::dynarray<ot::impact_info>& landed_tracers() const;

    ///Destroy tracer object before end of lifetime
    void destroy_tracer( uint tracer );

    ///Create a crater directly
    //@param pos ECEF world position
    //@param radius approximate crater radius
    void make_crater( const double3& pos, float radius );

    ///Create smoke emitter
    //@param pos ECEF world position
    //@param norm smoke ejection direction (normalized pos for the upward dir)
    //@param radius approximate emitter radius
    //@param speed ejection speed
    //@param density smoke density
    //@param fade_time duration of the smoke effect
    //@param color smoke color
    //@param age age in seconds at the creation time
    uint create_smoke( const double3& pos, const float3& norm, float radius, float speed, float density, float fade_time, float timeout, const float3& color, float age = 0, uint id = UMAX32 );

    //@param id smoke emitter id
    void destroy_smoke( uint id );

    ///Create explosion of solid particles
    //@param pos ECEF world position
    //@param norm smoke ejection direction (normalized pos for the upward dir)
    //@param emitter_radius radius of the emitter area
    //@param particle_radius max particle radius, old eq: 0.04f * stdmax(1.0f, glm::log2(emitter_radius));
    //@param speed ejection speed
    //@param spread direction dissipation, tangent of the half-angle
    //@param highlight 0:solid, 1+:water spray
    //@param age age in seconds at the creation time
    //@param bcolor base particle color
    //@param hcolor highlight color in rgb (can be >1 for bloom), w: highlight inverse size coefficient
    uint create_solid_particles( const double3& pos, const float3& norm, float emitter_radius, float particle_radius, float speed, float spread = 0.4f, float highlight = 0.0f, float age = 0, const float3& bcolor = float3(0.03, 0.02, 0.01), const float4& hcolor = float4(40, 6, 0, 10), uint id = UMAX32 );

    //@param id particle emitter id
    void destroy_solid_particles( uint id );

    void reset( bool smoke, bool craters );

    ///Create infra beam device
    //@return device id
    //@param brightness beam light power
    //@param half_distance distance over which the beam loses half of its power due to air attenuation
    uint create_beam( float brightness = 100.0f, float half_distance = 7000.0f );

    void destroy_beam( uint id );

    ///Turn the beam on
    void beam_on( uint beam, const double3& from, const double3& to, float brightness = 0 );

    ///Turn the beam off
    void beam_off( uint beam );

    // --- creators ---

    static iref<explosions> get() {
        return get<explosions>(0);
    }

    template<class T>
    static iref<T> get( T* _subclass_ );

    // --- internal helpers ---

    ///Interface revision hash
    static const int HASHID = 1231380986;

    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::explosions";
        return _name;
    }

    int intergen_hash_id() const override final { return HASHID; }

    bool iface_is_derived( int hash ) const override final {
        return hash == HASHID;
    }

    const coid::tokenhash& intergen_interface_name() const override final {
        return IFCNAME();
    }

    static const coid::token& intergen_default_creator_static( EBackend bck ) {
        static const coid::token _dc("ot::explosions.get@1231380986");
        static const coid::token _djs("ot::explosions@wrapper.js");
        static const coid::token _djsc("ot::explosions@wrapper.jsc");
        static const coid::token _dlua("ot::explosions@wrapper.lua");
        static const coid::token _dnone;

        switch(bck) {
        case IFC_BACKEND_CXX: return _dc;
        case IFC_BACKEND_JS:  return _djs;
        case IFC_BACKEND_JSC:  return _djsc;
        case IFC_BACKEND_LUA: return _dlua;
        default: return _dnone;
        }
    }

    template<enum EBackend B>
    static void* intergen_wrapper_cache() {
        static void* _cached_wrapper=0;
        if (!_cached_wrapper) {
            const coid::token& tok = intergen_default_creator_static(B);
            _cached_wrapper = coid::interface_register::get_interface_creator(tok);
        }
        return _cached_wrapper;
    }

    void* intergen_wrapper( EBackend bck ) const override final {
        switch(bck) {
        case IFC_BACKEND_JS: return intergen_wrapper_cache<IFC_BACKEND_JS>();
        case IFC_BACKEND_JSC: return intergen_wrapper_cache<IFC_BACKEND_JSC>();
        case IFC_BACKEND_LUA: return intergen_wrapper_cache<IFC_BACKEND_LUA>();
        default: return 0;
        }
    }

    EBackend intergen_backend() const override { return IFC_BACKEND_CXX; }

    const coid::token& intergen_default_creator( EBackend bck ) const override final {
        return intergen_default_creator_static(bck);
    }

    ///Client registrator
    template<class C>
    static int register_client()
    {
        static_assert(std::is_base_of<explosions, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::explosions";
        tmp << "@client-1231380986" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    explosions()
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> explosions::get( T* _subclass_ )
{
    typedef iref<T> (*fn_creator)(explosions*);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::explosions.get@1231380986";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("get", "ot::explosions.get", "@1231380986");
        return 0;
    }

    return create(_subclass_);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline uint explosions::launch_combo( const double3& pos, const float3& speed, float size, const float3& color, const float3& smoke_color, float emitter_radius, float emitter_speed, float particle_size, float smoke_timeout, bool crater, bool solids, bool smoke )
{ return VT_CALL(uint,(const double3&,const float3&,float,const float3&,const float3&,float,float,float,float,bool,bool,bool),0)(pos,speed,size,color,smoke_color,emitter_radius,emitter_speed,particle_size,smoke_timeout,crater,solids,smoke); }

inline uint explosions::launch_tracer( const double3& pos, const float3& speed, float size, const float3& color, float fadeout, float trail, float timeout, float age, uint tracer_id, uint entid, uint uservalue )
{ return VT_CALL(uint,(const double3&,const float3&,float,const float3&,float,float,float,float,uint,uint,uint),1)(pos,speed,size,color,fadeout,trail,timeout,age,tracer_id,entid,uservalue); }

inline void explosions::flash( const double3& pos, float intensity, const float4& color, float range, float timeout )
{ return VT_CALL(void,(const double3&,float,const float4&,float,float),2)(pos,intensity,color,range,timeout); }

inline const coid::dynarray<ot::impact_info>& explosions::landed_tracers() const
{ return VT_CALL(const coid::dynarray<ot::impact_info>&,() const,3)(); }

inline void explosions::destroy_tracer( uint tracer )
{ return VT_CALL(void,(uint),4)(tracer); }

inline void explosions::make_crater( const double3& pos, float radius )
{ return VT_CALL(void,(const double3&,float),5)(pos,radius); }

inline uint explosions::create_smoke( const double3& pos, const float3& norm, float radius, float speed, float density, float fade_time, float timeout, const float3& color, float age, uint id )
{ return VT_CALL(uint,(const double3&,const float3&,float,float,float,float,float,const float3&,float,uint),6)(pos,norm,radius,speed,density,fade_time,timeout,color,age,id); }

inline void explosions::destroy_smoke( uint id )
{ return VT_CALL(void,(uint),7)(id); }

inline uint explosions::create_solid_particles( const double3& pos, const float3& norm, float emitter_radius, float particle_radius, float speed, float spread, float highlight, float age, const float3& bcolor, const float4& hcolor, uint id )
{ return VT_CALL(uint,(const double3&,const float3&,float,float,float,float,float,float,const float3&,const float4&,uint),8)(pos,norm,emitter_radius,particle_radius,speed,spread,highlight,age,bcolor,hcolor,id); }

inline void explosions::destroy_solid_particles( uint id )
{ return VT_CALL(void,(uint),9)(id); }

inline void explosions::reset( bool smoke, bool craters )
{ return VT_CALL(void,(bool,bool),10)(smoke,craters); }

inline uint explosions::create_beam( float brightness, float half_distance )
{ return VT_CALL(uint,(float,float),11)(brightness,half_distance); }

inline void explosions::destroy_beam( uint id )
{ return VT_CALL(void,(uint),12)(id); }

inline void explosions::beam_on( uint beam, const double3& from, const double3& to, float brightness )
{ return VT_CALL(void,(uint,const double3&,const double3&,float),13)(beam,from,to,brightness); }

inline void explosions::beam_off( uint beam )
{ return VT_CALL(void,(uint),14)(beam); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__explosions_H__
