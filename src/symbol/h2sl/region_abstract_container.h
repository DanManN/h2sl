/**
 * @file region.h
 *
 * @brief
 *
 * a class that describes a region in relation to an container
 */

#ifndef H2SL_REGION_ABSTRACT_CONTAINER_H
#define H2SL_REGION_ABSTRACT_CONTAINER_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/common.h"
#include "h2sl/grounding.h"
#include "h2sl/symbol_dictionary.h"

namespace h2sl {
  /**
   * Region_Abstract_Container class definition
   */
  class Region_Abstract_Container : public Grounding {
  public:
    Region_Abstract_Container( const std::string& spatialRelationType = "na",
                                const std::string& objectType = "na",
                                const int& number = 0,
                                const int& index = 0,
                                const std::string& colorType = "na" );
                              

    virtual ~Region_Abstract_Container();
    Region_Abstract_Container( const Region_Abstract_Container& other );
    Region_Abstract_Container( xmlNodePtr root );
    Region_Abstract_Container& operator=( const Region_Abstract_Container& other );
    bool operator==( const Region_Abstract_Container& other )const;
    bool operator!=( const Region_Abstract_Container& other )const;
    virtual Region_Abstract_Container* dup( void )const;
   
    virtual bool matches_class_name( const std::string& arg )const{ return ( arg == "region_abstract_container" ); };
    static void fill_search_space( const Symbol_Dictionary& symbolDictionary, const World* world, std::map< std::string, std::pair< unsigned int, std::vector< Grounding* > > >& searchSpaces, const symbol_type_t& symbolType ); 

    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline std::string& spatial_relation_type( void ){ 
              return get_prop< std::string >( _string_properties, "spatial_relation_type" ); };
    inline const std::string& spatial_relation_type( void )const{ 
              return get_prop< std::string >( _string_properties, "spatial_relation_type" ); };

    inline std::string& type( void ){
              return get_prop< std::string >( _string_properties, "object_type" ); };
    inline const std::string& type( void )const{
              return get_prop< std::string >( _string_properties, "object_type" ); };

    inline int& number( void ){
              return get_prop< int >( _int_properties, "number" ); };
    inline const int& number( void )const{
              return get_prop< int >( _int_properties, "number" ); };

    inline int& index( void ){
              return get_prop< int >( _int_properties, "index" ); };
    inline const int& index( void )const{
              return get_prop< int >( _int_properties, "index" ); };

    inline std::string& color( void ){
              return get_prop< std::string >( _string_properties, "object_color_type" ); };
    inline const std::string& color( void )const{
              return get_prop< std::string >( _string_properties, "object_color_type" ); };

    static std::string class_name( void ){ return "region_abstract_container"; };
   
  protected:

  private: 

  };

  /**
   * Region_Abstract_Container class ostream operator
   */ 
  std::ostream& operator<<( std::ostream& out, const Region_Abstract_Container& other );
}

#endif /* H2SL_REGION_ABSTRACT_CONTAINER_H */
