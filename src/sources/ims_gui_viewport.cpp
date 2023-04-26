#include "ims_gui.h"

void ImStudio::GUI::ShowViewport()
{
    // viewport的原始位置画buffer
    float viewport_Height = 90.0f;
    ImVec2 buffer_S(vp_S.x, vp_S.y - viewport_Height);
    bw.drawall(vp_P, buffer_S);

    ImVec2 viewport_P(vp_P.x, vp_P.y + buffer_S.y);
    ImVec2 viewport_S(vp_S.x, viewport_Height);
    ImGui::SetNextWindowPos(viewport_P);
    ImGui::SetNextWindowSize(viewport_S);
    ImGui::Begin("Viewport", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus);

    /// content-viewport
    {
        ImGui::Text("Buffer Window: %gx%g", bw.size.x, bw.size.y);
        ImGui::SameLine();
        utils::TextCentered("Make sure to lock widgets before interacting with them.", 1);
        ImGui::Text("Cursor: %gx%g", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);
        ImGui::Text("Objects: %d", static_cast<int>(bw.objects.size()));
        if (!bw.objects.empty()) ImGui::Text("Selected: %s", bw.getbaseobj(bw.selected_obj_id)->identifier.c_str());
        ImGui::Text("Performance: %.1f FPS", ImGui::GetIO().Framerate);
        utils::HelpMarker("Hotkeys:\nAlt + M - \"Add\" context menu\n"\
            "Left/Right Arrow - Cycle object selection\n"\
            "Ctrl + E - Focus on property field\nDelete - Delete selected object");

    }
    ImGui::End();
}