// automatically generated by the FlatBuffers compiler, do not modify

/**
 * @const
 * @namespace
 */
var nuraftmesgcfg = nuraftmesgcfg || {};

/**
 * @constructor
 */
nuraftmesgcfg.MesgFactoryConfig = function() {
  /**
   * @type {flatbuffers.ByteBuffer}
   */
  this.bb = null;

  /**
   * @type {number}
   */
  this.bb_pos = 0;
};

/**
 * @param {number} i
 * @param {flatbuffers.ByteBuffer} bb
 * @returns {nuraftmesgcfg.MesgFactoryConfig}
 */
nuraftmesgcfg.MesgFactoryConfig.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {nuraftmesgcfg.MesgFactoryConfig=} obj
 * @returns {nuraftmesgcfg.MesgFactoryConfig}
 */
nuraftmesgcfg.MesgFactoryConfig.getRootAsMesgFactoryConfig = function(bb, obj) {
  return (obj || new nuraftmesgcfg.MesgFactoryConfig).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {nuraftmesgcfg.MesgFactoryConfig=} obj
 * @returns {nuraftmesgcfg.MesgFactoryConfig}
 */
nuraftmesgcfg.MesgFactoryConfig.getSizePrefixedRootAsMesgFactoryConfig = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new nuraftmesgcfg.MesgFactoryConfig).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @returns {number}
 */
nuraftmesgcfg.MesgFactoryConfig.prototype.raftRequestDeadline = function() {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? this.bb.readUint16(this.bb_pos + offset) : 2;
};

/**
 * @param {number} value
 * @returns {boolean}
 */
nuraftmesgcfg.MesgFactoryConfig.prototype.mutate_raft_request_deadline = function(value) {
  var offset = this.bb.__offset(this.bb_pos, 4);

  if (offset === 0) {
    return false;
  }

  this.bb.writeUint16(this.bb_pos + offset, value);
  return true;
};

/**
 * @returns {number}
 */
nuraftmesgcfg.MesgFactoryConfig.prototype.dataRequestDeadline = function() {
  var offset = this.bb.__offset(this.bb_pos, 6);
  return offset ? this.bb.readUint16(this.bb_pos + offset) : 2;
};

/**
 * @param {number} value
 * @returns {boolean}
 */
nuraftmesgcfg.MesgFactoryConfig.prototype.mutate_data_request_deadline = function(value) {
  var offset = this.bb.__offset(this.bb_pos, 6);

  if (offset === 0) {
    return false;
  }

  this.bb.writeUint16(this.bb_pos + offset, value);
  return true;
};

/**
 * @param {flatbuffers.Builder} builder
 */
nuraftmesgcfg.MesgFactoryConfig.startMesgFactoryConfig = function(builder) {
  builder.startObject(2);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} raftRequestDeadline
 */
nuraftmesgcfg.MesgFactoryConfig.addRaftRequestDeadline = function(builder, raftRequestDeadline) {
  builder.addFieldInt16(0, raftRequestDeadline, 2);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} dataRequestDeadline
 */
nuraftmesgcfg.MesgFactoryConfig.addDataRequestDeadline = function(builder, dataRequestDeadline) {
  builder.addFieldInt16(1, dataRequestDeadline, 2);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
nuraftmesgcfg.MesgFactoryConfig.endMesgFactoryConfig = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {number} raftRequestDeadline
 * @param {number} dataRequestDeadline
 * @returns {flatbuffers.Offset}
 */
nuraftmesgcfg.MesgFactoryConfig.createMesgFactoryConfig = function(builder, raftRequestDeadline, dataRequestDeadline) {
  nuraftmesgcfg.MesgFactoryConfig.startMesgFactoryConfig(builder);
  nuraftmesgcfg.MesgFactoryConfig.addRaftRequestDeadline(builder, raftRequestDeadline);
  nuraftmesgcfg.MesgFactoryConfig.addDataRequestDeadline(builder, dataRequestDeadline);
  return nuraftmesgcfg.MesgFactoryConfig.endMesgFactoryConfig(builder);
}

/**
 * @constructor
 */
nuraftmesgcfg.NuraftMesgConfig = function() {
  /**
   * @type {flatbuffers.ByteBuffer}
   */
  this.bb = null;

  /**
   * @type {number}
   */
  this.bb_pos = 0;
};

/**
 * @param {number} i
 * @param {flatbuffers.ByteBuffer} bb
 * @returns {nuraftmesgcfg.NuraftMesgConfig}
 */
nuraftmesgcfg.NuraftMesgConfig.prototype.__init = function(i, bb) {
  this.bb_pos = i;
  this.bb = bb;
  return this;
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {nuraftmesgcfg.NuraftMesgConfig=} obj
 * @returns {nuraftmesgcfg.NuraftMesgConfig}
 */
nuraftmesgcfg.NuraftMesgConfig.getRootAsNuraftMesgConfig = function(bb, obj) {
  return (obj || new nuraftmesgcfg.NuraftMesgConfig).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {flatbuffers.ByteBuffer} bb
 * @param {nuraftmesgcfg.NuraftMesgConfig=} obj
 * @returns {nuraftmesgcfg.NuraftMesgConfig}
 */
nuraftmesgcfg.NuraftMesgConfig.getSizePrefixedRootAsNuraftMesgConfig = function(bb, obj) {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new nuraftmesgcfg.NuraftMesgConfig).__init(bb.readInt32(bb.position()) + bb.position(), bb);
};

/**
 * @param {nuraftmesgcfg.MesgFactoryConfig=} obj
 * @returns {nuraftmesgcfg.MesgFactoryConfig|null}
 */
nuraftmesgcfg.NuraftMesgConfig.prototype.mesgFactoryConfig = function(obj) {
  var offset = this.bb.__offset(this.bb_pos, 4);
  return offset ? (obj || new nuraftmesgcfg.MesgFactoryConfig).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
};

/**
 * @param {flatbuffers.Builder} builder
 */
nuraftmesgcfg.NuraftMesgConfig.startNuraftMesgConfig = function(builder) {
  builder.startObject(1);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} mesgFactoryConfigOffset
 */
nuraftmesgcfg.NuraftMesgConfig.addMesgFactoryConfig = function(builder, mesgFactoryConfigOffset) {
  builder.addFieldOffset(0, mesgFactoryConfigOffset, 0);
};

/**
 * @param {flatbuffers.Builder} builder
 * @returns {flatbuffers.Offset}
 */
nuraftmesgcfg.NuraftMesgConfig.endNuraftMesgConfig = function(builder) {
  var offset = builder.endObject();
  return offset;
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} offset
 */
nuraftmesgcfg.NuraftMesgConfig.finishNuraftMesgConfigBuffer = function(builder, offset) {
  builder.finish(offset);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} offset
 */
nuraftmesgcfg.NuraftMesgConfig.finishSizePrefixedNuraftMesgConfigBuffer = function(builder, offset) {
  builder.finish(offset, undefined, true);
};

/**
 * @param {flatbuffers.Builder} builder
 * @param {flatbuffers.Offset} mesgFactoryConfigOffset
 * @returns {flatbuffers.Offset}
 */
nuraftmesgcfg.NuraftMesgConfig.createNuraftMesgConfig = function(builder, mesgFactoryConfigOffset) {
  nuraftmesgcfg.NuraftMesgConfig.startNuraftMesgConfig(builder);
  nuraftmesgcfg.NuraftMesgConfig.addMesgFactoryConfig(builder, mesgFactoryConfigOffset);
  return nuraftmesgcfg.NuraftMesgConfig.endNuraftMesgConfig(builder);
}

// Exports for Node.js and RequireJS
this.nuraftmesgcfg = nuraftmesgcfg;
