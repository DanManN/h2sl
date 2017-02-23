/**
 * @file feature_max_x_region_abstract_container.cc
 *
 * @brief
 *
 * Class used to describe a feature of the region_abstract_container number
 */
#include <assert.h>
#include <sstream>
#include <algorithm>

#include "h2sl/spatial_relation.h"
#include "h2sl/feature_max_x_region_abstract_container.h"
#include "h2sl/region_abstract_container.h"
#include "h2sl/region_container.h"

using namespace std;
using namespace h2sl;

bool
max_x_region_abstract_container_sort (Grounding* a, Grounding* b) {
    if ((dynamic_cast< const Object* >(a) != NULL) && (dynamic_cast< const Object* >(b) != NULL)) {
        return ( ((dynamic_cast< const Object* >(a))->transform().position().x()) <
                ((dynamic_cast< const Object* >(b))->transform().position().x()) );
    } else {
        cout << "Cannot cast container entity into Object" << endl;
        return false;
    }
}

/**
 * Feature_Max_X_Region_Abstract_Container class constructor
 */
Feature_Max_X_Region_Abstract_Container::
Feature_Max_X_Region_Abstract_Container( const bool& invert,
                          const std::string& relation_type ) : Feature( invert ),
                                                                          _relation_type( relation_type ) {

}

/**
 * Feature_Max_X_Region_Abstract_Container class copy constructor
 */
Feature_Max_X_Region_Abstract_Container::
Feature_Max_X_Region_Abstract_Container( const Feature_Max_X_Region_Abstract_Container& other ) : Feature( other ),
                                                              _relation_type( other._relation_type ) {

}

/**
 * Feature_Max_X_Region_Abstract_Container class destructor
 */
Feature_Max_X_Region_Abstract_Container::
~Feature_Max_X_Region_Abstract_Container() {

}

/** 
 * Feature_Max_X_Region_Abstract_Container class assignment operator
 */
Feature_Max_X_Region_Abstract_Container&
Feature_Max_X_Region_Abstract_Container::
operator=( const Feature_Max_X_Region_Abstract_Container& other ){
  _invert = other._invert;
  _relation_type = other._relation_type;
  return (*this);
}

/**
 * returns the value of the feature
 */
bool
Feature_Max_X_Region_Abstract_Container::
value( const unsigned int& cv,
      const Grounding* grounding,
      const vector< pair< const Phrase*, vector< Grounding* > > >& children,
      const Phrase* phrase,
      const World* world) {
    return value( cv, grounding, children, phrase, world, NULL );
    
}

/**
 * returns the value of the feature
 */
bool
Feature_Max_X_Region_Abstract_Container::
value( const unsigned int& cv,
        const h2sl::Grounding* grounding,
        const vector< pair< const h2sl::Phrase*, vector< h2sl::Grounding* > > >& children,
        const h2sl::Phrase* phrase,
        const World* world,
        const Grounding* context ){
  const Object* object_grounding = dynamic_cast< const Object* >( grounding );
  if( object_grounding != NULL ){
    Region_Abstract_Container* region_abstract_container_child = NULL;
    Container* container_child = NULL;
    for( unsigned int i = 0; i < children.size(); i++ ){
      for( unsigned int j = 0; j < children[ i ].second.size(); j++ ){
        if( dynamic_cast< Region_Abstract_Container* >( children[ i ].second[ j ] ) != NULL ){
          region_abstract_container_child = static_cast< Region_Abstract_Container* >( children[ i ].second[ j ] );
        } else if ( dynamic_cast< Container* >( children[ i ].second[ j ] ) != NULL ){
          container_child = static_cast< Container* >( children[ i ].second[ j ] );
        }
      }
    }
    
    if( region_abstract_container_child != NULL ){
      if( container_child != NULL ){
        if( container_child->type() == _relation_type ){
          map< string, vector< Object* > >::const_iterator it;
          it  = world->max_x_sorted_objects().find( region_abstract_container_child->spatial_relation_type() );
          if (it != world->max_x_sorted_objects().end() ) {
            for (unsigned int i = 0; i < it->second.size(); i++ ) {
              if ( *object_grounding == *(it->second[ i ]) ) {
//                map< string, unsigned int >::const_iterator itnum = world->numeric_map().find( region_abstract_container_child->number() );
//                assert( itnum != world->numeric_map().end() );
//                if( i < itnum->second ){
                if( i < region_abstract_container_child->number() ){
                    return !_invert;
                } else {
                    return _invert;
                }
              }
            }
          }
        }
      }
    }
  }
  return false;
}
    
/*  if( region_abstract_container_child != NULL ){
    if( region_abstract_container_child->spatial_relation_type() == _relation_type ){
      if( container_child != NULL ){
        if( object_grounding != NULL ){
 	  vector< Object* > objects_container = container_child->container();
          vector < Object* > objects;
          for ( unsigned int i = 0; i < objects_container.size(); i++ ) {
            if ( region_abstract_container_child->spatial_relation_type() == objects_container[ i ]->type() ){
              objects.push_back( objects_container[ i ] );
            }
          }
	  sort( objects.begin(), objects.end(), max_x_sort_region_abstract_container );
          
	  for( unsigned int i = 0; i < objects.size(); i++ ){
            if( *object_grounding == *objects[ i ] ){
              if( i < region_abstract_container_child->num() ){
                return !_invert;
              } else {
                  return _invert;
              }
            }
          }
        }
      }
    }
  }
  return false;
}*/

/** 
 * imports the Feature_Max_X_Region_Abstract_Container class from an XML file
 */
void
Feature_Max_X_Region_Abstract_Container::
from_xml( const string& filename ){
  xmlDoc * doc = NULL;
  xmlNodePtr root = NULL;
  doc = xmlReadFile( filename.c_str(), NULL, 0 );
  if( doc != NULL ){
    root = xmlDocGetRootElement( doc );
    if( root->type == XML_ELEMENT_NODE ){
      xmlNodePtr l1 = NULL;
      for( l1 = root->children; l1; l1 = l1->next ){
        if( l1->type == XML_ELEMENT_NODE ){
          if( xmlStrcmp( l1->name, ( const xmlChar* )( "feature_max_x_region_abstract_container" ) ) == 0 ){
            from_xml( l1 );
          }
        }
      }
      xmlFreeDoc( doc );
    }
  }  
  return;
}

/** 
 * imports the Feature_Max_X_Region_Abstract_Container class from an XML node pointer
 */
void
Feature_Max_X_Region_Abstract_Container::
from_xml( xmlNodePtr root ){
  _invert = false;
  _relation_type = "na";
  if( root->type == XML_ELEMENT_NODE ){
    xmlChar * tmp = xmlGetProp( root, ( const xmlChar* )( "invert" ) );
    if( tmp != NULL ){
      string invert_string = ( const char* )( tmp );
      _invert = ( bool ) ( strtol( invert_string.c_str(), NULL, 10 ) );
      xmlFree( tmp );
    }
    tmp = xmlGetProp( root, ( const xmlChar* )( "relation_type" ) );
    if( tmp != NULL){
      string relation_type_string = ( const char* )( tmp );
       _relation_type = relation_type_string;
      xmlFree( tmp );
    }
  }
}

/**
 * exports the Feature_Max_X_Region_Abstract_Container class to an XML file
 */
void
Feature_Max_X_Region_Abstract_Container::
to_xml( const string& filename )const{
  xmlDocPtr doc = xmlNewDoc( ( xmlChar* )( "1.0" ) );
  xmlNodePtr root = xmlNewDocNode( doc, NULL, ( xmlChar* )( "root" ), NULL );
  xmlDocSetRootElement( doc, root );
  to_xml( doc, root );
  xmlSaveFormatFileEnc( filename.c_str(), doc, "UTF-8", 1 );
  xmlFreeDoc( doc );
  return;
}

/**
 * exports the Feature_Max_X_Region_Abstract_Container class to an XML node pointer
 */
void
Feature_Max_X_Region_Abstract_Container::
to_xml( xmlDocPtr doc,
        xmlNodePtr root )const{
  xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "feature_max_x_region_abstract_container" ), NULL );
  stringstream invert_string;
  invert_string << _invert;
  xmlNewProp( node, ( const xmlChar* )( "invert" ), ( const xmlChar* )( invert_string.str().c_str() ) );
  xmlNewProp( node, ( const xmlChar* )( "relation_type" ), ( const xmlChar* )( _relation_type.c_str() ) );
  xmlAddChild( root, node );
  return;
}

std::string&
Feature_Max_X_Region_Abstract_Container::
relation_type( void ){
  return _relation_type;
}

const std::string&
Feature_Max_X_Region_Abstract_Container::
relation_type( void )const{
  return _relation_type;
}

namespace h2sl {
  /** 
   * Feature_Max_X_Region_Abstract_Container class ostream operator
   */
  ostream&
  operator<<( ostream& out,
              const Feature_Max_X_Region_Abstract_Container& other ){
    out << "class:\"Feature_Max_X_Region_Abstract_Container\" ";
    out << "relation_type:\"" << other.relation_type() << "\" ";
    return out;
  }
}
