#pragma once

#include <map>
#include <string>

#include "imgui.h"

#include "ims_utils.h"
#include "ims_object.h"
#include "ims_buffer.h"
#include "ims_generator.h"

#ifdef __EMSCRIPTEN__
#include "JsClipboardTricks.h"
#endif

namespace ImStudio
{

    struct GUI
    {
        bool                    state                      = true;                 // Alive
        bool                    compact                    = false;                // Compact/Spacious Switch
        bool                    wksp_create                = true;                 // Workspace "Create"

        bool                    menubar                    = true;                 // Menubar State
        ImVec2                  mb_P                       = {};                   // Menubar Pos
        ImVec2                  mb_S                       = {};                   // Menubar Size
        void                    ShowMenubar();         

        bool                    sidebar                    = true;                 // Sidebar State
        ImVec2                  sb_P                       = {};                   // Sidebar Pos
        ImVec2                  sb_S                       = {};                   // Sidebar Size
        void                    ShowSidebar();         

        bool                    properties                 = true;                 // Properties State
        ImVec2                  pt_P                       = {};                   // Properties Pos
        ImVec2                  pt_S                       = {};                   // Properties Size
        void                    ShowProperties();      

        bool                    viewport                   = true;                 // Viewport State
        ImVec2                  vp_P                       = {};                   // Viewport Pos
        ImVec2                  vp_S                       = {};                   // Viewport Size
        BufferWindow            bw;            
        void                    ShowViewport               ();         

        bool                    wksp_output                = false;                // Workspace "Output"
        ImVec2                  ot_P                       = {};                   // Output Window Pos
        ImVec2                  ot_S                       = {};                   // Output Window Size
        std::string             output                     = {};
        void                    ShowOutputWorkspace();        

        bool                    child_style                = false;                // Show Style Editor
        bool                    child_demo                 = false;                // Show Demo Window
        bool                    child_metrics              = false;                // Show Metrics Window
        bool                    child_color                = false;                // Show Color Export
        bool                    child_stack                = false;                // Show Stack Tool
        bool                    child_resources            = false;                // Show Help Resources
        bool                    child_about                = false;                // Show About Window
        
    };

}