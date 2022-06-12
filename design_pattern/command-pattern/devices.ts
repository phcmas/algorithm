class Light {
  constructor(private location: string) {}

  on() {
    console.log(`${this.location} light on`);
  }

  off() {
    console.log(`${this.location} light off`);
  }
}

class Stereo {
  private volume = 10;

  constructor(private location: string, volume?: number) {
    if (volume) {
      this.volume = volume;
    }
  }

  on() {
    console.log(`${this.location} stereo on`);
  }

  off() {
    console.log(`${this.location} stereo off`);
  }

  setVolume(volume: number) {
    console.log(`volume: ${this.volume}`);
    this.volume = volume;
  }
}

class CeilingFan {
  static HIGH = 3;
  static LOW = 1;
  static OFF = 0;
  private speed = 10;

  constructor(private location: string, speed?: number) {
    if (speed) {
      this.speed = speed;
    }
  }

  high() {
    this.speed = CeilingFan.HIGH;
    console.log(`speed: ${this.speed} location: ${this.location}`);
  }

  low() {
    this.speed = CeilingFan.LOW;
    console.log(`speed: ${this.speed} location: ${this.location}`);
  }

  off() {
    this.speed = CeilingFan.OFF;
    console.log(`speed: ${this.speed} location: ${this.location}`);
  }

  getSpeed() {
    return this.speed;
  }
}

export { Light, Stereo, CeilingFan };
