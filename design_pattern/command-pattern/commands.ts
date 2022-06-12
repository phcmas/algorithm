import { CeilingFan, Light, Stereo } from "./devices";

interface Command {
  execute(): void;
  undo(): void;
}

class NoCommand implements Command {
  execute(): void {
    throw new Error("no command");
  }

  undo(): void {
    throw new Error("no command");
  }
}

class LightOnCommand implements Command {
  constructor(private light: Light) {}

  execute(): void {
    this.light.on();
  }

  undo(): void {
    this.light.off();
  }
}

class LightOffCommand implements Command {
  constructor(private light: Light) {}

  execute(): void {
    this.light.off();
  }

  undo(): void {
    this.light.on();
  }
}

class StereoOnCommand implements Command {
  private defaultVolumne = 11;
  constructor(private stereo: Stereo) {}

  execute(): void {
    this.stereo.on();
    this.stereo.setVolume(this.defaultVolumne);
  }

  undo(): void {
    this.stereo.off();
  }
}

class StereoOffCommand implements Command {
  private defaultVolumne = 11;
  constructor(private stereo: Stereo) {}

  execute(): void {
    this.stereo.off();
  }

  undo(): void {
    this.stereo.on();
    this.stereo.setVolume(this.defaultVolumne);
  }
}

class CeilingFanHighCommand implements Command {
  private prevSpeed: number;

  constructor(private ceilingFan: CeilingFan) {
    this.prevSpeed = CeilingFan.OFF;
  }

  execute(): void {
    this.prevSpeed = this.ceilingFan.getSpeed();
    this.ceilingFan.high();
  }

  undo(): void {
    switch (this.prevSpeed) {
      case CeilingFan.HIGH:
        this.ceilingFan.high();
        break;
      case CeilingFan.LOW:
        this.ceilingFan.low();
        break;
      case CeilingFan.OFF:
        this.ceilingFan.off();
        break;
    }
  }
}

class CeilingFanLowCommand implements Command {
  private prevSpeed: number;

  constructor(private ceilingFan: CeilingFan) {
    this.prevSpeed = CeilingFan.OFF;
  }

  execute(): void {
    this.prevSpeed = this.ceilingFan.getSpeed();
    this.ceilingFan.low();
  }

  undo(): void {
    switch (this.prevSpeed) {
      case CeilingFan.HIGH:
        this.ceilingFan.high();
        break;
      case CeilingFan.LOW:
        this.ceilingFan.low();
        break;
      case CeilingFan.OFF:
        this.ceilingFan.off();
        break;
    }
  }
}

class CeilingFanOffCommand implements Command {
  private prevSpeed: number;

  constructor(private ceilingFan: CeilingFan) {
    this.prevSpeed = CeilingFan.OFF;
  }

  execute(): void {
    this.prevSpeed = this.ceilingFan.getSpeed();
    this.ceilingFan.off();
  }

  undo(): void {
    switch (this.prevSpeed) {
      case CeilingFan.HIGH:
        this.ceilingFan.high();
        break;
      case CeilingFan.LOW:
        this.ceilingFan.low();
        break;
      case CeilingFan.OFF:
        this.ceilingFan.off();
        break;
    }
  }
}

export {
  Command,
  NoCommand,
  LightOnCommand,
  LightOffCommand,
  StereoOnCommand,
  StereoOffCommand,
  CeilingFanHighCommand,
  CeilingFanLowCommand,
  CeilingFanOffCommand,
};
