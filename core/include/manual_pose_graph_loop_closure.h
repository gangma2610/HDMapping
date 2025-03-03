#ifndef _manual_pose_graph_loop_closure_h_
#define _manual_pose_graph_loop_closure_h_

#include <point_clouds.h>
#include <gnss.h>

class ManualPoseGraphLoopClosure{
    public:
        struct Edge
        {
            TaitBryanPose relative_pose_tb;
            TaitBryanPose relative_pose_tb_weights;
            int index_from;
            int index_to;
        };

        std::vector<Edge> edges;
        int index_active_edge = 0;
        bool manipulate_active_edge = false;
        bool gizmo = false;
        double search_radious = 0.3;

        std::vector<Eigen::Affine3d> poses_motion_model;

        ManualPoseGraphLoopClosure(){};
        ~ManualPoseGraphLoopClosure(){};

        void Gui(PointClouds &point_clouds_container, int &index_loop_closure_source, int &index_loop_closure_target, float *m_gizmo, GNSS &gnss);
        void Render(PointClouds &point_clouds_container, int index_loop_closure_source, int index_loop_closure_target);
};

#endif
