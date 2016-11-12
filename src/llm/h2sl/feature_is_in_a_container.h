/**
 * @file feature_is_in_a_container.h
 * 
 * @brief
 * 
 * Class used to describe a feature of the abstract_container number
 */

#ifndef H2SL_FEATURE_IS_IN_A_CONTAINER_H
#define H2SL_FEATURE_IS_IN_A_CONTAINER_H

#include <iostream>
#include <libxml/tree.h>

#include "h2sl/feature.h"
#include "h2sl/object.h"
namespace h2sl {
  /**
   * Feature_Is_In_A_Container class definition
   */
  class Feature_Is_In_A_Container : public Feature {
  public:
    Feature_Is_In_A_Container( const bool& invert = false, const std::string& container_type = "na" );
    Feature_Is_In_A_Container( const Feature_Is_In_A_Container& other );
    virtual ~Feature_Is_In_A_Container();
    Feature_Is_In_A_Container& operator=( const Feature_Is_In_A_Container& other );
 
    virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world );
    virtual bool value( const unsigned int& cv, const h2sl::Grounding* grounding, const std::vector< std::pair< const h2sl::Phrase*, std::vector< h2sl::Grounding* > > >& children, const h2sl::Phrase* phrase, const World* world, const Grounding* context );
    
    std::pair< double, double > convert_to_rho_theta(double x, double y);   
 
    bool in_a_row( const Object* local_root_object, std::vector< Object* > all_objects, const Object* global_root_object, unsigned int container_size, unsigned int counter );    
    bool in_a_column( const Object* local_root_object, std::vector< Object* > all_objects, const Object* global_root_object, unsigned int container_size, unsigned int counter );    
    bool in_a_tower();    

    virtual void from_xml( const std::string& file );
    virtual void from_xml( xmlNodePtr root );
    virtual void to_xml( const std::string& file )const;
    virtual void to_xml( xmlDocPtr doc, xmlNodePtr root )const;

    std::string& container_type( void );
    const std::string& container_type( void )const;
    
    bool& is_a_container( void );
    const bool& is_a_container( void )const;
    void set_is_a_container( bool );
    
    bool& direction( void );
    const bool& direction( void )const;
    void set_direction( bool );
    
    void set_max_object_count( unsigned int );    
    unsigned int& max_object_count( void );
    const unsigned int& max_object_count( void )const;
 
    virtual inline const h2sl::feature_type_t type( void )const{ return h2sl::FEATURE_TYPE_GROUNDING; };

  protected:
    const double _rho;
    const double _theta;
    std::string _container_type;
    unsigned int _max_object_count;
    bool _direction;
    bool _is_a_container;
  private:

  };

  /** 
   * Feature_Is_In_A_Container class ostream operator
   */
  std::ostream& operator<<( std::ostream& out, const Feature_Is_In_A_Container& other );
}

#endif /* H2SL_FEATURE_IS_IN_A_CONTAINER_H */
