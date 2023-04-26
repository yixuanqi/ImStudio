#pragma once

#include <string>
#include <vector>

#include "imgui.h"

#include "ims_object.h"

namespace ImStudio
{

  class BufferWindow
  {
    public:
      bool                    state                   = true;                //
      ImVec2                  size                    = {};                   //
      ImVec2                  pos                     = {};                   //
      int                     idgen                   = 0;                    //
      bool                    open_child              = false;                //
      int                     open_child_id           = -1;                   //
      int                     selected_obj_id         = -1;                   //
    
      bool                    staticlayout            = false;                //
    
      std::vector<Object>     objects                 = {};                   //
  
      void                    drawall                 (ImVec2 &vp_P, ImVec2 &vp_S);
      Object *                getobj                  (int id);
      BaseObject *            getbaseobj              (int id);
      void                    create                  (std::string type_, bool atcursor = false);
  };

}