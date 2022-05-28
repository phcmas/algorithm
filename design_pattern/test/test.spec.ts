import {
  Duck,
  MallardDuck,
  ModelDuck,
  RubberDuck,
} from "../strategy-pattern/duck";
import { FlyRocketPowered } from "../strategy-pattern/fly-behavior";

describe("common utility test", () => {
  it("strategy pattern", () => {
    const mallard = new MallardDuck();
    mallard.display();
    mallard.performFly();
    mallard.performQuack();

    const model = new ModelDuck();
    model.performFly();
    model.performQuack();
    model.setFlyBehavior(new FlyRocketPowered());
    model.performFly();

    const rubber = new RubberDuck();
    rubber.performFly();
    rubber.performQuack();
  });
});
