#include <gtest/gtest.h>

#include "Mocks.h"

#include "../src/AnimatedGraphic.h"

TEST(AnimatedGraphicTest, TestLoad) {
  std::unique_ptr<MockLoaderParams> mockParams =
      std::make_unique<MockLoaderParams>();

  AnimatedGraphic animatedGraphic;
  std::unique_ptr<LoaderParams> params =
      std::static_pointer_cast<LoaderParams>(std::move(mockParams));
  animatedGraphic.load(params);

  EXPECT_CALL(*mockParams, getX()).WillOnce(testing::Return(100));
  EXPECT_CALL(*mockParams, getY()).WillOnce(testing::Return(100));
  EXPECT_CALL(*mockParams, getWidth()).WillOnce(testing::Return(128));
  EXPECT_CALL(*mockParams, getHeight()).WillOnce(testing::Return(128));
  EXPECT_CALL(*mockParams, getTextureID()).WillOnce(testing::Return("animate"));

  //   EXPECT_EQ(animatedGraphic.getX(), 100);
  //   EXPECT_EQ(animatedGraphic.getY(), 100);
  //   EXPECT_EQ(animatedGraphic.getWidth(), 128);
  //   EXPECT_EQ(animatedGraphic.getHeight(), 128);
  //   EXPECT_EQ(animatedGraphic.getTextureID(), "animate");
}

TEST(AnimatedGraphicTest, TestUpdate) {
  AnimatedGraphic animatedGraphic;
  int currentFrame = animatedGraphic.getCurrentFrame();
  animatedGraphic.update();
  EXPECT_EQ(animatedGraphic.getCurrentFrame(),
            currentFrame + 1); // assuming update increments the frame
}

TEST(AnimatedGraphicTest, TestClean) {
  AnimatedGraphic animatedGraphic;
  animatedGraphic.clean();
  EXPECT_EQ(animatedGraphic.isDead(), true);
}

TEST(AnimatedGraphicCreatorTest, TestCreate) {
  AnimatedGraphicCreator creator;
  GameObject *gameObject = creator.createGameObject();
  EXPECT_EQ(dynamic_cast<AnimatedGraphic *>(gameObject) != nullptr, true);
}
