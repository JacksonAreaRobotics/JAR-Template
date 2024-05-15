import React from 'react';
import ComponentCreator from '@docusaurus/ComponentCreator';

export default [
  {
    path: '/JAR-Template/',
    component: ComponentCreator('/JAR-Template/', '0b4'),
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
        path: '/JAR-Template/docs/autonomous-functions',
        component: ComponentCreator('/JAR-Template/docs/autonomous-functions', '08d'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/drive-constructor',
        component: ComponentCreator('/JAR-Template/docs/drive-constructor', '25c'),
        exact: true,
        sidebar: "tutorialSidebar"
      },
      {
        path: '/JAR-Template/docs/usercontrol-functions',
        component: ComponentCreator('/JAR-Template/docs/usercontrol-functions', 'f79'),
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
