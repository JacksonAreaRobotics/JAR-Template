import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
  {
    path: '/JAR-Template/',
    component: ComponentCreator('/JAR-Template/', '6d5'),
    routes: [
      {
        path: '/JAR-Template/',
        component: ComponentCreator('/JAR-Template/', '1f0'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/advanced-tutorials',
        component: ComponentCreator('/JAR-Template/advanced-tutorials', 'df1'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/advanced-tutorials/using-drive-member-variables',
        component: ComponentCreator('/JAR-Template/advanced-tutorials/using-drive-member-variables', '033'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/basic-tutorials',
        component: ComponentCreator('/JAR-Template/basic-tutorials', 'd5f'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/basic-tutorials/basic-usage',
        component: ComponentCreator('/JAR-Template/basic-tutorials/basic-usage', 'c43'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/basic-tutorials/installing-jar-template',
        component: ComponentCreator('/JAR-Template/basic-tutorials/installing-jar-template', '1af'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs',
        component: ComponentCreator('/JAR-Template/docs', '88d'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/drive-class',
        component: ComponentCreator('/JAR-Template/docs/drive-class', 'f32'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/drive-class/drive-constructor',
        component: ComponentCreator('/JAR-Template/docs/drive-class/drive-constructor', '452'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/drive-class/general-functions',
        component: ComponentCreator('/JAR-Template/docs/drive-class/general-functions', '4d3'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/drive-class/motion-functions',
        component: ComponentCreator('/JAR-Template/docs/drive-class/motion-functions', '742'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/odometry-class',
        component: ComponentCreator('/JAR-Template/docs/odometry-class', 'e23'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/PID-class',
        component: ComponentCreator('/JAR-Template/docs/PID-class', '4a6'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/utility-functions',
        component: ComponentCreator('/JAR-Template/docs/utility-functions', 'fb4'),
        exact: true,
        sidebar: "tutorialSidebar"
      }
    ]
  },
  {
    path: '*',
    component: ComponentCreator('*'),
  },
];
