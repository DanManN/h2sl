/**
 * @file feature_abstract_container_color.h
 * 
 * @brief
 * 
 * Class used to describe a feature of the abstract_container color
 */

#ifndef H2SL_FEATURE_ABSTRACT_CONTAINER_COLOR_H
#define H2SL_FEATURE_ABSTRACT_CONTAINER_COLOR_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"

namespace h2sl {
  /**
   * Feature_Abstract_Container_Color class definition
   */
  class Feature_Abstract_Container_Color : public Feature {
  public:
    Feature_Abstract_Container_Color( const bool& invert = false, const std::string& abstract_container_color = "na" );
    Feature_Abstract_Container_Color( const Feature_Abstract_Container_Color& other );
    virtual ~Feature_Abstract_Container_Color();
    Feature_Abstract_Container_Color& operator=( const Feature_Abstract_Container_Color& other );
 
    virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world );
    
    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    std::string& abstract_container_color( void );
    const std::string& abstract_container_color( void )const;

    virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };

  protected:
    std::string _abstract_container_color;

  private:

  };

  /** 
   * Feature_Abstract_Container_Color class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Feature_Abstract_Container_Color& other );
}

#endif /* H2SL_FEATURE_ABSTRACT_CONTAINER_COLOR_H */
