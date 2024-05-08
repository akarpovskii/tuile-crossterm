const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const strip_symbols = b.dependency("build.crab", .{
        .target = target,
        .optimize = optimize,
    }).artifact("strip_symbols");

    const run_strip_symbols = b.addRunArtifact(strip_symbols);
    if (b.args) |args| {
        run_strip_symbols.addArgs(args);
    }

    const strip_step = b.step("strip", "Run strip symbols");
    strip_step.dependOn(&run_strip_symbols.step);
}
