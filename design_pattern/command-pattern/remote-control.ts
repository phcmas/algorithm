import { Command, NoCommand } from "./commands";

const commandSize = 7;

class RemoteControl {
  private onCommands: Command[];
  private offCommands: Command[];
  private undoCommand: Command;

  constructor() {
    const noCommand = new NoCommand();
    this.onCommands = new Array(commandSize).fill(noCommand);
    this.offCommands = new Array(commandSize).fill(noCommand);
    this.undoCommand = noCommand;
  }

  setCommand(slot: number, onCommand: Command, offCommand: Command) {
    this.onCommands[slot] = onCommand;
    this.offCommands[slot] = offCommand;
  }

  pressOnButton(slot: number) {
    this.onCommands[slot].execute();
    this.undoCommand = this.onCommands[slot];
  }

  pressOffButton(slot: number) {
    this.offCommands[slot].execute();
    this.undoCommand = this.offCommands[slot];
  }

  pressUndoButtion() {
    this.undoCommand.undo();
  }
}

export { RemoteControl };
