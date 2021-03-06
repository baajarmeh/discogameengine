#pragma once

#include <asset/asset.h>
#include <runtime/texture.h>
#include <graphicsinterface/graphicsinterface.h>
#include <engine>

namespace runtime {
struct Texture2DResource;
struct Texture2D : public Texture, public asset::Asset {
  declare_asset_type(Texture2D);

  virtual void serialize(Archive &archive) override;
  virtual renderer::Resource *create_resource() override;
  virtual void init_resource() override;
  virtual void update_resource() override;
  virtual void release_resource() override;

  virtual u16 get_size_x() const override {
    return size_x;
  }
  virtual u16 get_size_y() const override {
    return size_y;
  }

  virtual graphicsinterface::PixelFormat get_pixel_format() const override {
    return pixel_format;
  }

  Texture2DResource *get_resource();

  Blob texture_data;
  virtual void free() override {
    texture_data.free();
  }

  u16 size_x = 0;
  u16 size_y = 0;

  graphicsinterface::PixelFormat pixel_format = graphicsinterface::PixelFormat::Unknown;

private:
  Texture2DResource *resource = nullptr;
};
} // namespace runtime
