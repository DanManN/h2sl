/**
 * @file feature_container_object_type.h
 * 
 * @brief
 * 
 * Class used to describe a feature of the container object_type
 */

#ifndef H2SL_FEATURE_CONTAINER_OBJECT_TYPE_H
#define H2SL_FEATURE_CONTAINER_OBJECT_TYPE_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"

namespace h2sl {
  /**
   * Feature_Container_Object_Type class definition
   */
  class Feature_Container_Object_Type : public Feature {
  public:
    Feature_Container_Object_Type( const bool& invert = false, const std::string& objectType = "na" );
    Feature_Container_Object_Type( xmlNodePtr root );
    Feature_Container_Object_Type( const Feature_Container_Object_Type& other );
    virtual ~Feature_Container_Object_Type();
    Feature_Container_Object_Type& operator=( const Feature_Container_Object_Type& other );
 
    virtual bool value( const std::string& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world );
    virtual bool value( const std::string& cv, const Grounding* grounding, const std::vector< std::pair< const Phrase*, std::vector< Grounding* > > >& children, const Phrase* phrase, const World* world, const Grounding* context );
    
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    inline std::string& object_type( void ){ return get_prop< std::string >( _string_properties, "object_type" ); };
    inline const std::string& object_type( void )const{ return get_prop< std::string >( _string_properties, "object_type" ); };

    virtual inline const feature_type_t type( void )const{ return FEATURE_TYPE_GROUNDING; };

  protected:

  private:

  };

  /** 
   * Feature_Container_Object_Type class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Feature_Container_Object_Type& other );
}

#endif /* H2SL_FEATURE_CONTAINER_OBJECT_TYPE_H */
