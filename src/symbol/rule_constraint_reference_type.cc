/**
 * @file rule_constraint_reference_type.cc
 *
 * @brief
 *
 * a class used to describe a spatial relationship
 */

#include <assert.h>

#include "h2sl/rule_constraint_reference_type.h"

using namespace std;
using namespace h2sl;

/**
 * Rule_Constraint_Reference_Type class constructor
 */
Rule_Constraint_Reference_Type::
Rule_Constraint_Reference_Type( const string& constraintReferenceType ) : Rule() {
  insert_prop< std::string >( _string_properties, "constraint_reference_type", constraintReferenceType );
}

Rule_Constraint_Reference_Type::
Rule_Constraint_Reference_Type( xmlNodePtr root ) : Rule() {
  insert_prop< std::string >( _string_properties, "constraint_reference_type", "na" );
  from_xml( root );
}

/**
 * Rule_Constraint_Reference_Type class copy constructor
 */
Rule_Constraint_Reference_Type::
Rule_Constraint_Reference_Type( const Rule_Constraint_Reference_Type& other ) : Rule( other ) {

}

/**
 * Rule_Constraint_Reference_Type class destructor
 */
Rule_Constraint_Reference_Type::
~Rule_Constraint_Reference_Type() {

}

/** 
 * Rule_Constraint_Reference_Type class assignment operator
 */
Rule_Constraint_Reference_Type&
Rule_Constraint_Reference_Type::
operator=( const Rule_Constraint_Reference_Type& other ){
  _string_properties = other._string_properties;
  _int_properties = other._int_properties;
  return (*this);
}

/** 
 * Rule_Constraint_Reference_Type class equality operator
 */
bool
Rule_Constraint_Reference_Type::
operator==( const Rule_Constraint_Reference_Type& other )const{
  if ( constraint_reference_type() != other.constraint_reference_type() ){
    return false;
  } else {
    return true;
  }
}

/** 
 * Rule_Constraint_Reference_Type class inequality operator
 */
bool
Rule_Constraint_Reference_Type::
operator!=( const Rule_Constraint_Reference_Type& other )const{
  return !( *this == other );
}

/** 
 * Rule_Constraint_Reference_Type class dup operator
 */
Rule_Constraint_Reference_Type*
Rule_Constraint_Reference_Type::
dup( void )const{
  return new Rule_Constraint_Reference_Type( *this );
}

void
Rule_Constraint_Reference_Type::
scrape_grounding( const World * world,
                  map< string, vector< string > >& stringTypes,
                  map< string, vector< int > >& intTypes )const{
  insert_unique< std::string >( "constraint_reference_type", constraint_reference_type(), stringTypes );
  return;
}

void
Rule_Constraint_Reference_Type::
scrape_grounding( const World * world,
                  vector< string >& classNames,
                  map< string, vector< string > >& stringTypes,
                  map< string, vector< int > >& intTypes )const{
  insert_unique< std::string >( class_name(), classNames );
  scrape_grounding( world, stringTypes, intTypes );
  return;
}

void
Rule_Constraint_Reference_Type::
fill_search_space( const Symbol_Dictionary& symbolDictionary,
                    const World* world,
                    map< string, pair< string, vector< Grounding* > > >& searchSpaces,
                    const symbol_type_t& symbolType ){

  if( symbolDictionary.has_class_name( "constraint" ) ){
    map< string, pair< string, vector< Grounding* > > >::iterator it_search_spaces_symbol = searchSpaces.find( class_name() );
    if( it_search_spaces_symbol == searchSpaces.end() ){
      searchSpaces.insert( pair< string, pair< string, vector< Grounding* > > >( class_name(), pair< string, vector< Grounding* > >( "binary", vector< Grounding* >() ) ) );
      it_search_spaces_symbol = searchSpaces.find( class_name() );
    }

    map< string, vector< string > >::const_iterator it_constraint_reference_type_types = symbolDictionary.string_types().find( "constraint_reference_type" );

    switch( symbolType ){
    case( SYMBOL_TYPE_CONCRETE ):
    case( SYMBOL_TYPE_ALL ):
      if( it_constraint_reference_type_types != symbolDictionary.string_types().end() ){
        for( unsigned int i = 0; i < it_constraint_reference_type_types->second.size(); i++ ){
          it_search_spaces_symbol->second.second.push_back( new Rule_Constraint_Reference_Type( it_constraint_reference_type_types->second[ i ] ) );
        }
      }
      break;
    case( SYMBOL_TYPE_ABSTRACT ):
    case( NUM_SYMBOL_TYPES ):
    default:
      break;
    }
  }

  return;
}

/** 
 * imports the Rule_Constraint_Reference_Type class from an XML file
 */
void
Rule_Constraint_Reference_Type::
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
          if( xmlStrcmp( l1->name, ( const xmlChar* )( "rule_constraint_reference_type" ) ) == 0 ){
            from_xml( l1 );
          }
        }
      }
      xmlFreeDoc( doc );
    } else {
      xmlFreeDoc( doc );
    }
  }
  return;
}

/** 
 * imports the Rule_Constraint_Reference_Type class from an XML node pointer
 */
void
Rule_Constraint_Reference_Type::
from_xml( xmlNodePtr root ){
  constraint_reference_type() = "na";
  if( root->type == XML_ELEMENT_NODE ){
    vector< string > constraint_reference_type_keys = { "type", "constraint_reference_type" };
    assert( check_keys( root, constraint_reference_type_keys ) );
    pair< bool, string > constraint_reference_type_prop = has_prop< std::string >( root, "constraint_reference_type" );
    if( constraint_reference_type_prop.first ){
      constraint_reference_type() = constraint_reference_type_prop.second;
    }
    constraint_reference_type_prop = has_prop< std::string >( root, "type" );
    if( constraint_reference_type_prop.first ){
      constraint_reference_type() = constraint_reference_type_prop.second;
    }
  }
  return;
}

/**
 * exports the Rule_Constraint_Reference_Type class to an XML file
 */
void
Rule_Constraint_Reference_Type::
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
 * exports the Rule_Constraint_Reference_Type class to an XML node pointer
 */
void
Rule_Constraint_Reference_Type::
to_xml( xmlDocPtr doc,
        xmlNodePtr root )const{
  xmlNodePtr node = xmlNewDocNode( doc, NULL, ( xmlChar* )( "rule_constraint_reference_type" ), NULL );
  xmlNewProp( node, ( const xmlChar* )( "constraint_reference_type" ), ( const xmlChar* )( get_prop< std::string >( _string_properties, "constraint_reference_type" ).c_str() ) );
  xmlAddChild( root, node );
  return;
}

namespace h2sl {
  /** 
   * Rule_Constraint_Reference_Type class ostream operator
   */
  ostream&
  operator<<( ostream& out,
              const Rule_Constraint_Reference_Type& other ){
    out << "Rule_Constraint_Reference_Type(";
    out << "constraint_reference_type=\"" << other.constraint_reference_type() << "\"";
    out << ")";
    return out;
  }
}
