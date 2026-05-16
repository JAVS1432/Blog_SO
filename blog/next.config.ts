import type { NextConfig } from "next";

const nextConfig: NextConfig = {
  /* config options here */
  reactCompiler: true,
  async redirects() {
    return [
      {
        source: "/linux",
        destination: "/linux.html",
        permanent: false,
      },
      {
        source: "/procesos",
        destination: "/procesos.html",
        permanent: false,
      },
      {
        source: "/ipc",
        destination: "/ipc.html",
        permanent: false,
      },
      {
        source: "/terminal",
        destination: "/terminal.html",
        permanent: false,
      },
      {
        source: "/equipo",
        destination: "/equipo.html",
        permanent: false,
      },
      {
        source: "/index",
        destination: "/index.html",
        permanent: false,
      },
    ];
  },
};

export default nextConfig;
