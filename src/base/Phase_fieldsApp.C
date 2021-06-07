#include "Phase_fieldsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Phase_fieldsApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

Phase_fieldsApp::Phase_fieldsApp(InputParameters parameters) : MooseApp(parameters)
{
  Phase_fieldsApp::registerAll(_factory, _action_factory, _syntax);
}

Phase_fieldsApp::~Phase_fieldsApp() {}

void
Phase_fieldsApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"Phase_fieldsApp"});
  Registry::registerActionsTo(af, {"Phase_fieldsApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Phase_fieldsApp::registerApps()
{
  registerApp(Phase_fieldsApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Phase_fieldsApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Phase_fieldsApp::registerAll(f, af, s);
}
extern "C" void
Phase_fieldsApp__registerApps()
{
  Phase_fieldsApp::registerApps();
}
